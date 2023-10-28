local scripts = {
	--[[
	BenchmarkV = {
		Name = "BenchmarkV",
		FileName = "BenchmarkV.txt",
		Vanilla = true
	},
	BenchmarkS = {
		Name = "BenchmarkS",
		FileName = "BenchmarkS.txt",
		Vanilla = false
	},
	benchmarkoldV = {
		Name = "benchmarkoldV",
		FileName = "benchmarkoldV.txt",
		Vanilla = true
	},
	benchmarkoldS = {
		Name = "benchmarkoldS",
		FileName = "benchmarkoldS.txt",
		Vanilla = false
	},
	DexV = {
		Name = "DexV",
		FileName = "DexV.txt",
		Vanilla = true
	},
	DexS = {
		Name = "DexS",
		FileName = "DexS.txt",
		Vanilla = false
	},
	SelfTest = {
		Name = "SelfTest",
		FileName = "selftestV.txt",
		Vanilla = true
	},
	DexAprilS = {
		Name = "DexAprilS",
		FileName = "DexAprilS.txt",
		Vanilla = false
	},
	DexAprilV = {
		Name = "DexAprilV",
		FileName = "DexAprilV.txt",
		Vanilla = true
	},
	Linoria1 = {
		Name = "Linoria1",
		FileName = "Linoria1.txt",
		Vanilla = false
	},]]
	newestlin = {
		Name = "newestlin",
		FileName = "newestlin.txt",
		Vanilla = false
	},--[[
	kir = {
		Name = "kir",
		FileName = "kir.txt",
		Vanilla = false
	},
	aztup = {
		Name = "aztup",
		FileName = "aztup.txt",
		Vanilla = false
	},
	Linoria2 = {
		Name = "Linoria2",
		FileName = "Linoria2.txt",
		Vanilla = false
	},
	LustrisV = {
		Name = "LustrisV",
		FileName = "LustrisV.txt",
		Vanilla = true
	},
	dexold1_v = {
		Name = "dexold1_v",
		FileName = "dexold1_v.txt",
		Vanilla = true
	},
	dexold1 = {
		Name = "dexold1",
		FileName = "dexold1.txt",
		Vanilla = false
	},
	simpleprint = {
		Name = "simpleprint",
		FileName = "simpleprint.txt",
		Vanilla = false
	},]]
}

local VMSurvey = false
local targetVM = "Alpha"

local ignoreKeyCorrect = {
	["00 00 34 cb "] = true,
	["00 00 64 42 "] = true,
	["00 00 ad 24 "] = true,
	["00 00 21 f2 "] = true,
	["00 00 99 3e "] = true,
	["00 00 91 23 "] = true,
}

local selfBytes = {
	["00 00 59 c0 "] = true,
	["00 00 74 f7 "] = true,
	["00 00 bc 27 "] = true,
	["00 00 c3 d0 "] = true,
	["00 00 cb bc "] = true,
	["00 00 e4 78 "] = true,
	["00 00 e7 a4 "] = true,
}

local knowns = {
	-- UNK1
	["00 00 48 9f "] = 7,
	["00 00 5e d0 "] = 7,
	["00 00 a0 c1 "] = 7,
	
	-- REST
	["00 00 d7 7e "] = 37,
	["00 00 f5 fc "] = 37,
	["00 00 f7 b9 "] = 16,
	["00 00 52 c9 "] = 17,
	["00 00 78 4a "] = 17,
	["00 00 c8 3e "] = 37,
}


local function readfile(f)
	local file = io.open(f, "rb")

	-- sets the default input file as test.lua
	io.input(file)

	-- prints the first line of the file
	local f = io.read("*a")

	-- closes the open file
	io.close(file)

	return f
end

local function writefile(f,data)
	local file = io.open(f, "wb")

	-- sets the default input file as test.lua
	io.output(file)

	-- prints the first line of the file
	local f = io.write(data)

	-- closes the open file
	io.close(file)

	return f
end

local function isfile(f)
	local res = io.open(f,"r")
	return res and true or false
end

if not warn then
	warn = print
end

load([==[
bit32 = {
	extract = function(n,p,w)
		return n >> p & 2^w-1
	end
}
]==])()

local vmCounts = {
	Alpha = 0,
	Beta = 0,
	Charlie = 0
}


local keyToInstr = {}
for bytes,op in pairs(knowns) do
	keyToInstr[bytes] = {
		Bytes = bytes,
		Op = op,
		Samples = {},
		Diffs = {},
		HasDiff = false
	}
end


local opcodes = {
	"OP_MOVE",
	"OP_LOADK",
	"OP_LOADBOOL",
	"OP_LOADNIL",
	"OP_GETUPVAL",
	"OP_GETGLOBAL",
	"OP_GETTABLE",
	"OP_SETGLOBAL",
	"OP_SETUPVAL",
	"OP_SETTABLE",
	"OP_NEWTABLE",
	"OP_SELF",
	"OP_ADD",
	"OP_SUB",
	"OP_MUL",
	"OP_DIV",
	"OP_MOD",
	"OP_POW",
	"OP_UNM",
	"OP_NOT",
	"OP_LEN",
	"OP_CONCAT",
	"OP_JMP",
	"OP_EQ",
	"OP_LT",
	"OP_LE",
	"OP_TEST",
	"OP_TESTSET",
	"OP_CALL",
	"OP_TAILCALL",
	"OP_RETURN",
	"OP_FORLOOP",
	"OP_FORPREP",
	"OP_TFORLOOP",
	"OP_SETLIST",
	"OP_CLOSE",
	"OP_CLOSURE",
	"OP_VARARG",
}


local opmodes = {
	"A B ",
	"A Bx ",
	"A B C",
	"A B ",
	"A B ",
	"A Bx ",
	"A B C",
	"A Bx ",
	"A B ",
	"A B C",
	"A B C",
	"A B C",
	"A B C",
	"A B C",
	"A B C",
	"A B C",
	"A B C",
	"A B C",
	"A B ",
	"A B ",
	"A B ",
	"A B C",
	"sBx  ",
	"A B C",
	"A B C",
	"A B C",
	"A C ",
	"A B C",
	"A B C",
	"A B C",
	"A B ",
	"A sBx ",
	"A sBx ",
	"A C ",
	"A B C",
	"A  ",
	"A Bx ",
	"A B ",
}

local function bytestring(s)
	local r = s:gsub(".",function(c)
		return ("%02x "):format(c:byte())
	end)
	return r
end

local extr = bit32.extract

local function bitToStr(num,pos)
	return extr(num,pos) == 0 and "0" or "1"
end

local function bitstring(s)
	local r = s:gsub(".",function(c)
		local num = c:byte()
		local str = ""
		for i = 0,7 do
			str = bitToStr(num,i)..str
		end
		return str
	end)
	return r
end

local vmNameMap = {
	[12287] = "Alpha",
	[16383] = "Beta",
	[20479] = "Charlie"
}

local realPrint = print
local realWarn = warn

local opcodeMap = {}

local function readScript(data)
	local vanilla = data.Vanilla
	
	print("READING SCRIPT",data.Name)
	
	local tonumber = tonumber
	local stringChar = string.char
	
	local strBuffer
	
	if isfile(data.FileName.."_cache") then
		strBuffer = readfile(data.FileName.."_cache")
	else
		local bytes = readfile(data.FileName)
		local buffer = {}
		local bufferNextInd = 1
		for w in bytes:gmatch("%x%x") do
			buffer[bufferNextInd] = stringChar(tonumber(w,16))
			bufferNextInd = bufferNextInd + 1
		end
		strBuffer = table.concat(buffer)
		writefile(data.FileName.."_cache",strBuffer)
	end

	local pointer = 1
	local function read(n)
		n = n or 1
		local str = strBuffer:sub(pointer,pointer+n-1)
		pointer  = pointer + n
		return str
	end

	local function readString()
		local len = string.unpack("<I4",read(4))
		return read(len)
	end

	local function readInt()
		local n = string.unpack("<I4",read(4))
		return n
	end

	local function readNumber()
		local n  = string.unpack("<d",read(8))
		return n
	end
	
	local function printread(caption,n)
		local bytestr = read(n)
		local hex = bytestr:gsub(".",function(c)
			return ("%02x "):format(c:byte())
		end)
		print(caption..": "..hex.." "..bytestr)
	end
	
	read(4)--printread("Sig",4)
	read(1)--printread("Ver",1)
	read(1)--printread("Format",1)
	read(1)--printread("Endian",1)
	read(1)--printread("sizeint",1)
	read(1)--printread("sizesize_t",1)
	read(1)--printread("sizeinstr",1)
	read(1)--printread("sizeluanumber",1)
	read(1)--printread("integral",1)
	
	local scriptData = {}
	local scriptFuncs = {}
	scriptData.Funcs = scriptFuncs

	local function readFunc()
		local funcData = {}

		local srcSize = readInt()
		read(srcSize)
		--warn("SOURCE",srcSize)
		local lineDefined = readInt()
		local lastLineDefined = readInt()

		read(1+1+1+1)

		local vmName = vmNameMap[lineDefined]

		local sizecode = readInt()
		--warn(vmName..": STARTING TO READ A FUNC WITH NUM INSTRS = ",sizecode)
		if VMSurvey and not vanilla then
			--print = function() end
			--warn = function() end

			if not vmCounts[vmName] then error("NEW VM",lineDefined,vmName) end
			vmCounts[vmName] = vmCounts[vmName] + 1
		end
		--print("LINE DEFINED",lineDefined)
		--print("LAST LINE DEFINED",lastLineDefined)

		local funcOps = {}

		if vanilla then
			for i = 1,sizecode do
				local instrKey = read(4)
				--local instrKeyBytes = string.pack(">I4",string.unpack("<I4",instrKey))
				--local instrNum = string.unpack("<I4",instrKey)
				--local op = bit32.extract(instrNum,0,6)
				--local secPC = 2*(i-1)
				--print(tostring(2*(i-1))..")","OP",op,"INST:",bytestring(instrKeyBytes))

				table.insert(funcOps,instrKey)


				--local opmode = vOpmodes[op]
				--if opmode == "ABC" then
				--	local a = bit32.extract(instrNum,6,8)
				--	local c = bit32.extract(instrNum,14,9)
				--	local b = bit32.extract(instrNum,23,9)
				--	--warn("A",a,"B",b,"C",c)
				--end
			end
		else
			for i = 1,sizecode/2 do
				local instrKey = read(4)
				local instrData = read(4)
--[[
				local instrKeyBytes = string.pack(">I4",string.unpack("<I4",instrKey))
				local instrDataBytes = string.pack(">I4",string.unpack("<I4",instrData))

				local instrKeyNum = string.unpack("<I4",instrKey)
				local instrDataNum = string.unpack("<I4",instrData)
				]]

				local relPc = 2*(i-1)
				local afterPc = i*8

				-- TODO: setlist C = 0?
				table.insert(funcOps,{instrKey,instrData})

				--local decrypted = secdec(vmName,afterPc,instrKeyNum,instrDataNum)
				--local decryptedBytes = string.pack(">I4",decrypted)


				--if i % 2 == 0 then instrNum = bit32.bxor(instrNum,4294967295) end

				--local op = bit32.extract(instrNum,0,6)
				--local op = bytestring(instrKeyBytes)
				--opcodeMap[op] = if opcodeMap[op] then opcodeMap[op] + 1 else 1
				--if i % 2 == 0 then continue end

				--local op = bytestring(instrKeyBytes)
				--if opcodeMap[op] then
				--	opcodeMap[op] = opcodeMap[op] + 1
				--else
				--	opcodeMap[op] = 1
				--end

				--local decdpart = ""

				--if decrypted ~= 0 then
				--	decdpart = "DEC'D:  "..bytestring(decryptedBytes)
				--end

				--print(tostring(relPc)..")","Key:",bytestring(instrKeyBytes),"Data:",bytestring(instrDataBytes),decdpart)
			end
		end

		local consts = {}

		local sizek = readInt()
		--print("NUM CONSTS",sizek)
		for i = 1,sizek do
			local typ = read(1):byte()
			if typ == 0 then
				--print("NIL")
				table.insert(consts,"nil")
			elseif typ == 1 then
				--print("BOOL",read(1) == "\1" and "true" or "false")
				table.insert(consts, read(1) == "\1" and "true" or "false")
			elseif typ == 3 then
				--print("LUA_NUMBER", tostring(readNumber()))
				table.insert(consts,readNumber())
			elseif typ == 4 then
				local str = readString()
				--print("STR", str)
				table.insert(consts,str:sub(1,#str-1))
			else
				error("INAVLID CONST TYPE "..tostring(typ))
			end
		end

		local sizep = readInt()
		--print("NUM PROTOS",sizek)
		for i = 1,sizep do
			readFunc()
		end

		local sizeSourceLine = readInt()
		--print("NUM SOURCE LINE",sizeSourceLine)
		for i = 1,sizeSourceLine do
			readInt()
			--print(i,readInt())
		end

		local sizeLoc = readInt()
		--print("NUM LOCALS",sizeLoc)
		for i = 1,sizeLoc do
			--print(i,readString(),readInt(),readInt())
			readString()readInt()readInt()
		end

		local sizeUps = readInt()
		--print("NUM UPVALS",sizeUps)
		for i = 1,sizeUps do
			--print(i,readString())
			readString()
		end

		funcData.Code = funcOps
		funcData.Consts = consts
		funcData.VM = vmName

		--warn("END OF THE FUNC WITH NUM INSTRS = ",sizecode)
		table.insert(scriptFuncs,funcData)
	end
	
	readFunc(0)
	local re = read(#strBuffer)
	--print("REMAINING DATA",#re)
	
	data.Data = scriptData
end

local function mapOpcodes(vanilla,secure,data)
	data = data or {
		IgnoreConsts = {}
	}
	
	local ignoreConsts = data.IgnoreConsts
	
	local vFuncs = {}
	for i,v in pairs(vanilla.Data.Funcs) do
		table.insert(vFuncs,v)
	end
	
	local sFuncs = {}
	for i,v in pairs(secure.Data.Funcs) do
		table.insert(sFuncs,v)
	end
	
	local toCompare = {}
	
	if data.Type == "OneToMany" then
	else
		-- Default
		
		--if #vFuncs ~= #sFuncs then error("NOT SAME NUM OF FUNCS") end
		
		for i = 1,math.min(#vFuncs,#sFuncs) do
			local vFunc,sFunc = vFuncs[i],sFuncs[i]
			
			if #vFunc.Code == #sFunc.Code and #vFunc.Consts == #sFunc.Consts and sFunc.VM == targetVM then
				if vFunc.Consts[1] == sFunc.Consts[1] and vFunc.Consts[#vFunc.Consts] == sFunc.Consts[#sFunc.Consts] then
					local ignored = false
					for i,v in pairs(sFunc.Consts) do
						if ignoreConsts[v] then
							ignored = true
						end
					end
				
					if not ignored then table.insert(toCompare,{vFunc,sFunc}) end
				end
			end
		end
	end
	
	print("COMPARING",#toCompare,"FUNCS IN",vanilla.Name,"AND",secure.Name)
	
	for funcNum,data in pairs(toCompare) do
		local vFunc,sFunc = data[1],data[2]
		local vCode,sCode = vFunc.Code,sFunc.Code
		
		local selfStack = {}
		
		local vanCount,secCount = 1,1
		
		for i = 1,#vCode do
			if not vCode[vanCount] or not sCode[secCount] then break end
			
			local vanInstr = vCode[vanCount]
			
			--local vanBytes = bytestring(string.pack(">I4",string.unpack("<I4",vanInstr)))
			local vanNum = string.unpack("<I4",vanInstr)
			local op = bit32.extract(vanNum,0,6)
			
			while true do
				if op == 11 then
					table.insert(selfStack,vanInstr)
					vanCount = vanCount + 1
					vanInstr = vCode[vanCount]
					vanNum = string.unpack("<I4",vanInstr)
					op = bit32.extract(vanNum,0,6)
				else
					break
				end
			end
			
			local instrKey = sCode[secCount][1]
			local instrData = sCode[secCount][2]
			local instrKeyBytes = bytestring(string.pack(">I4",string.unpack("<I4",instrKey)))
			
			while true do
				if selfBytes[instrKeyBytes] then
					local correspondingVan = table.remove(selfStack)
					local correspondingSec = {instrKey,instrData,instrKeyBytes,secCount*8}
					
					secCount = secCount + 1
					instrKey = sCode[secCount][1]
					instrData = sCode[secCount][2]
					instrKeyBytes = bytestring(string.pack(">I4",string.unpack("<I4",instrKey)))
					--print("MATCHED SELFS",bytestring(string.pack(">I4",string.unpack("<I4",correspondingVan))),bytestring(string.pack(">I4",string.unpack("<I4",correspondingSec[1]))))
					
					
					if keyToInstr[correspondingSec[3]] == nil then
						keyToInstr[correspondingSec[3]] = {
							Bytes = correspondingSec[3],
							Op = 11,
							Samples = {},
							Diffs = {},
							HasDiff = false
						}
					end
					
					local samps = keyToInstr[correspondingSec[3]].Samples
					samps[correspondingSec[4]] = {correspondingSec[4],correspondingSec[1],correspondingSec[2],correspondingVan,11}

					local diffCounts = keyToInstr[correspondingSec[3]].Diffs
					diffCounts[11] = diffCounts[11] and diffCounts[11] + 1 or 1
					
					
				else
					break
				end
			end
			
			--local instrDataBytes = bytestring( string.pack(">I4",string.unpack("<I4",instrData)))

			--local instrKeyNum = string.unpack("<I4",instrKey)
			--local instrDataNum = string.unpack("<I4",instrData)
			
			
			local secAfterPC = secCount*8
			
			if keyToInstr[instrKeyBytes] == nil then
				keyToInstr[instrKeyBytes] = {
					Bytes = instrKeyBytes,
					Op = op,
					Samples = {},
					Diffs = {},
					HasDiff = false
				}
			else
				if keyToInstr[instrKeyBytes].Op ~= op then
					--[[
					local msg = "DIFF OPCODES "..tostring(opcodes[op+1]).." and "..tostring(opcodes[keyToInstr[instrKeyBytes].Op+1])
					
					print(msg)
					for i,v in pairs(vFunc.Consts) do
						print(i,v)
					end
					print("AT",i)
					for i,vanInstr in pairs(vCode) do
						local vanNum = string.unpack("<I4",vanInstr)
						local op = bit32.extract(vanNum,0,6)
						
						local extra = ""
						if opmodes[op+1]:find("A B C") then
							local A = bit32.extract(vanNum,6,8)
							local C = bit32.extract(vanNum,14,9)
							local B = bit32.extract(vanNum,23,9)
							extra = extra.." "..A.." "..B.." "..C
						end
						
						
						print(i,opcodes[op+1],opmodes[op+1],extra)
					end
					print("SECLUA")
					for i,data in pairs(sCode) do
						local instrKey = data[1]
						local instrData = data[2]
						local instrKeyBytes = bytestring(string.pack(">I4",string.unpack("<I4",instrKey)))
						local secAfterPC = i*8
						local instrKeyNum = string.unpack("<I4",instrKey)
						local instrDataNum = string.unpack("<I4",instrData)
						local decryptedNum = secdec(targetVM,secAfterPC,instrKeyNum,instrDataNum)
						local op = bit32.extract(decryptedNum,0,6)
						local secOp = ""
						if op ~= 0 then
							secOp = opcodes[op+1].." "..opmodes[op+1]
							if opmodes[op+1]:find("A B C") then
								local A = bit32.extract(decryptedNum,6,8)
								local C = bit32.extract(decryptedNum,14,9)
								local B = bit32.extract(decryptedNum,23,9)
								secOp = secOp.." "..A.." "..B.." "..C
							end
						end
						print(i,instrKeyBytes,secOp)
					end
					error()
					]]
					keyToInstr[instrKeyBytes].HasDiff = true
					--print(msg)
					--local diffCounts = keyToInstr[instrKeyBytes].Diffs
					--diffCounts[op] = diffCounts[op] and diffCounts[op] + 1 or 1
					
					local samps = keyToInstr[instrKeyBytes].Samples
					samps[secAfterPC] = {secAfterPC,instrKey,instrData,vanInstr,op}

					local diffCounts = keyToInstr[instrKeyBytes].Diffs
					diffCounts[op] = diffCounts[op] and diffCounts[op] + 1 or 1
					
					break
				end
			end
			
			local samps = keyToInstr[instrKeyBytes].Samples
			samps[secAfterPC] = {secAfterPC,instrKey,instrData,vanInstr,op}
			
			local diffCounts = keyToInstr[instrKeyBytes].Diffs
			diffCounts[op] = diffCounts[op] and diffCounts[op] + 1 or 1
			
			--[[
			local secPC = i*8
			
			local decryptedNum = secdec(targetVM,secPC,instrKeyNum,instrDataNum)
			local decryptedBytes = bytestring(string.pack(">I4",decryptedNum))
			
			local eq = vanNum == decryptedNum
			print("EQ",secPC)
			]]
			
			vanCount = vanCount + 1
			secCount = secCount + 1
		end
	end
end

local function compareKeys()
	local funcDefs = ""
	local switchPart = ""
	local opsToCreate = {}
	local missing = {}
	
	local sorted = {}
	for key,data in pairs(keyToInstr) do table.insert(sorted,data) end
	table.sort(sorted,function(a,b) return a.Op < b.Op end)

	for _,data in pairs(sorted) do
		--print("-------- KEY",data.Bytes,opcodes[data.Op+1],data.Op,opmodes[data.Op+1])
		if data.HasDiff then
			--print("-------- KEY",data.Bytes,"HAS DIFFS")
			local sortedDiffs = {}
			for op,count in pairs(data.Diffs) do sortedDiffs[#sortedDiffs+1] = {op,count} end
			table.sort(sortedDiffs,function(a,b) return a[2] < b[2] end)
			for _,diffData in pairs(sortedDiffs) do
				--print(opcodes[diffData[1]+1],diffData[2])
			end
			data.Op = sortedDiffs[#sortedDiffs][1]
		end
			
		local printedKey = false

		local sortedSamps = {}
		for pc,data in pairs(data.Samples) do table.insert(sortedSamps,data) end
		table.sort(sortedSamps,function(a,b) return a[1] < b[1] end)
		
		local isMissing = true

		for _,sampData in pairs(sortedSamps) do
			if sampData[5] == data.Op then
				local secAfterPC = sampData[1]
				local realPC = secAfterPC/8-1

				local instrKeyNum = string.unpack("<I4",sampData[2])
				local instrDataNum = string.unpack("<I4",sampData[3])
				local vanNum = string.unpack("<I4",sampData[4])

				local decryptedNum = secdec(targetVM,secAfterPC,instrKeyNum,instrDataNum)

				local vanBytes = bytestring(string.pack(">I4",string.unpack("<I4",sampData[4])))
				local instrKeyBytes = bytestring(string.pack(">I4",string.unpack("<I4",sampData[2])))
				local instrDataBytes = bytestring( string.pack(">I4",string.unpack("<I4",sampData[3])))
				local decryptedBytes = bytestring(string.pack(">I4",decryptedNum))

				local decryptedRand = secdec(targetVM,2134,instrKeyNum,0xfafe34da)
				local decryptedRand2 = secdec(targetVM,1412,instrKeyNum,0x2ebc3405)

				if decryptedNum ~= 0 or decryptedRand ~= 0 or decryptedRand2 ~= 0 then
					isMissing = false
					if vanNum ~= decryptedNum then
						if not ignoreKeyCorrect[data.Bytes] then
							if not printedKey then
								print("-------- KEY",data.Bytes,opcodes[data.Op+1],data.Op,opmodes[data.Op+1])
								printedKey = true
							end
							print(("(%d) %s : %s -> %s [ %s]"):format(realPC,instrKeyBytes,instrDataBytes,decryptedBytes,vanBytes))
						end
					end
				--else
					--print(("MISSING KEY (%d) %s : %s -> [ %s]"):format(realPC,instrKeyBytes,instrDataBytes,vanBytes),opcodes[data.Op+1],data.Op,opmodes[data.Op+1])
					--missing[data.Bytes] = true
				end
			end
		end
		
		if isMissing then
			missing[data.Bytes] = true
		end

		local op = data.Op
		local t = opsToCreate[op] or {}
		opsToCreate[op] = t
		table.insert(t,data.Bytes)
	end
	
	local sorted = {}
	for i,v in pairs(opsToCreate) do table.insert(sorted,{i,v}) end
	table.sort(sorted,function(a,b) return a[1] < b[1] end)
	
	for _,createData in pairs(sorted) do		
		local op = createData[1]
		local keys = createData[2]
		table.sort(keys)
		
		local oneSwitch = "\n// "..opcodes[op+1] .. " "..tostring(op).. " : "..opmodes[op+1]
		
		for _,keyBytes in pairs(keys) do
			local key = keyBytes:gsub(" ",""):sub(5)
			
			funcDefs = funcDefs.."\n".."// "..opcodes[op+1] .. " "..tostring(op).. " : "..opmodes[op+1]
			funcDefs = funcDefs..("\nvoid d%s(instr* inst, uint param_1, uint param_2) {"):format(key)
			funcDefs = funcDefs.."\n\n\n\n\tinst->OP = "..op..";"
			for w in opmodes[op+1]:gmatch("%S+") do
				funcDefs = funcDefs.."\n\tinst->"..w.." = 0;"
			end
			funcDefs = funcDefs.."\n}\n\n\n"
			
			local missingPart = missing[keyBytes] and "//" or ""
			oneSwitch = oneSwitch..("\n\t"..missingPart.."case 0x%s: d%s(&inst, pc, data); break;"):format(key,key)
		end
		
		oneSwitch = oneSwitch.."\n"
		switchPart = switchPart..oneSwitch
	end
	
	local finalCode = funcDefs..string.rep("\n",4)..switchPart
	writefile("CodeDefs.cpp",finalCode)
end

local function countVanillaOps(scr)
	local numOps = 0
	local opCount = {}
	
	for i,v in pairs(scr.Data.Funcs) do
		print("--------------------- FUNC",#v.Code)
		for _,instr in pairs(v.Code) do
			local vanNum = string.unpack("<I4",instr)
			local op = bit32.extract(vanNum,0,6)
			
			if not opCount[op] then
				numOps = numOps + 1
				opCount[op] = 1
			else
				opCount[op] = opCount[op] + 1
			end
			
			print(opcodes[op+1])
		end
	end
	
	print(numOps,"DIFF OPCODES")
	for i,v in pairs(opCount) do
		print(opcodes[i+1],i,v)
	end
end

local function countSecureOps(scr)
	local numOps = 0
	local opCount = {}

	for i,v in pairs(scr.Data.Funcs) do
		print("--------------------- FUNC",#v.Code)
		for _,instr in pairs(v.Code) do
			local op = bytestring(string.pack(">I4",string.unpack("<I4",instr[1])))

			if not opCount[op] then
				numOps = numOps + 1
				opCount[op] = 1
			else
				opCount[op] = opCount[op] + 1
			end

			--print(opcodes[op+1])
		end
	end

	print(numOps,"DIFF OPCODES")
	return opCount
end

local function compareSecures(s1,s2,opts)
	local funcs1 = {}
	local funcs2 = {}
	
	opts = opts or {}
	local func1Start = opts.Func1Start or 1
	local func2Start = opts.Func2Start or 1
	
	
	for i,v in pairs(s1.Data.Funcs) do
		if i >= func1Start then
			table.insert(funcs1,v)
		end
	end
	
	for i,v in pairs(s2.Data.Funcs) do
		if i >= func2Start then
			table.insert(funcs2,v)
		end
	end
	
	local totalFuncs = math.min(#funcs1,#funcs2)
	
	local matched = {}
	
	--[[
	for i = 1,math.max(#funcs1,#funcs2) do
		local code1 = funcs1[i] and funcs1[i].Code or {}
		local code2 = funcs2[i] and funcs2[i].Code or {}
		if #code1 ~= #code2 then
			print(i,#code1,#code2)
		end
	end
	]]
	
	for i = 1,totalFuncs do
		local code1 = funcs1[i].Code
		local code2 = funcs2[i].Code
		
		if #code1 ~= #code2 then
			print("BREAK AT",i)
			break
		else
			for j = 1,#code1 do
				local key1 = code1[j][1]
				local key2 = code2[j][1]
				
				local data1 = code1[j][2]
				local data2 = code2[j][2]
				
				local afterPC = j*8
				
				local key1Bytes = bytestring(string.pack(">I4",string.unpack("<I4",key1)))
				local key2Bytes = bytestring(string.pack(">I4",string.unpack("<I4",key2)))
				
				if not keyToInstr[key1Bytes] then
					--if not matched[key1Bytes] then
					local other = keyToInstr[key2Bytes]
					if other then
							--print("MATCHED",key1Bytes,"TO",key2Bytes,opcodes[other.Op+1],other.Op)
						matched[key1Bytes] = matched[key1Bytes] or {}
						local opTable = matched[key1Bytes][other.Op]
						if not opTable then
							matched[key1Bytes][other.Op] = {1}
						else
							matched[key1Bytes][other.Op][1] = matched[key1Bytes][other.Op][1] + 1
						end
						
					end
					--end
				elseif not keyToInstr[key2Bytes] then
					--if not matched[key2Bytes] then
					local other = keyToInstr[key1Bytes]
					if other then
							--print("MATCHED",key2Bytes,"TO",key1Bytes,opcodes[other.Op+1],other.Op)
						matched[key2Bytes] = matched[key2Bytes] or {}
						local opTable = matched[key2Bytes][other.Op]
						if not opTable then
							matched[key2Bytes][other.Op] = {1}	
						else
							matched[key2Bytes][other.Op][1] = matched[key2Bytes][other.Op][1] + 1
						end
						
						table.insert(matched[key2Bytes][other.Op],{afterPC,key1,data1,key2,data2})
					end
					--end
				end
			end
		end
	end
	
	for key,matches in pairs(matched) do
		print("----------------------- KEY",key)
		local sortedDiffs = {}
		for op,matchData in pairs(matches) do sortedDiffs[#sortedDiffs+1] = {op,matchData} end
		table.sort(sortedDiffs,function(a,b) return a[2][1] < b[2][1] end)
		for _,data in pairs(sortedDiffs) do
			local op = data[1]
			local matchData = data[2]
			
			local count = matchData[1]
			
			print("----------",opcodes[op+1],op,"COUNT=",count)
			for i = 2,#matchData do
				local t = matchData[i]
				local afterPC = t[1]
				local key1 = t[2]
				local data1 = t[3]
				local key2 = t[4]
				local data2 = t[5]
				
				local instrKeyNum1 = string.unpack("<I4",key1)
				local instrDataNum1 = string.unpack("<I4",data1)
				local instrKeyNum2 = string.unpack("<I4",key2)
				local instrDataNum2 = string.unpack("<I4",data2)

				local decryptedNum1 = secdec(targetVM,afterPC,instrKeyNum1,instrDataNum1)
				local decryptedNum2 = secdec(targetVM,afterPC,instrKeyNum2,instrDataNum2)
				
				print("EQ",i-1,decryptedNum1 == decryptedNum2,bytestring(string.pack(">I4",decryptedNum1)),bytestring(string.pack(">I4",decryptedNum2)))
			end
		end
	end
end

local function convert(data)
	print("CONVERTING SCRIPT",data.Name)

	local tonumber = tonumber
	local stringChar = string.char

	local strBuffer
	
	local writeBuffer = {}

	if isfile(data.FileName.."_cache") then
		strBuffer = readfile(data.FileName.."_cache")
	else
		local bytes = readfile(data.FileName)
		local buffer = {}
		local bufferNextInd = 1
		for w in bytes:gmatch("%x%x") do
			buffer[bufferNextInd] = stringChar(tonumber(w,16))
			bufferNextInd = bufferNextInd + 1
		end
		strBuffer = table.concat(buffer)
		writefile(data.FileName.."_cache",strBuffer)
	end

	local pointer = 1
	local function read(n)
		n = n or 1
		local str = strBuffer:sub(pointer,pointer+n-1)
		pointer  = pointer + n
		return str
	end
	
	local function write(data)
		table.insert(writeBuffer,data)
	end
	
	local function readwrite(n)
		local by = read(n)
		write(by)
		return by
	end

	local function readString()
		local len = string.unpack("<I4",read(4))
		return read(len)
	end

	local function readInt()
		local n = string.unpack("<I4",read(4))
		return n
	end

	local function readNumber()
		local n  = string.unpack("<d",read(8))
		return n
	end
	
	local function readwriteString()
		local stuff = read(4)
		write(stuff)
		local len = string.unpack("<I4",stuff)
		local theStr = read(len)
		write(theStr)
		return theStr
	end

	local function readwriteInt()
		local by = read(4)
		write(by)
		local n = string.unpack("<I4",by)
		return n
	end

	local function readwriteNumber()
		local by = read(8)
		write(by)
		local n  = string.unpack("<d",by)
		return n
	end

	--[[local function printread(caption,n)
		local bytestr = read(n)
		local hex = bytestr:gsub(".",function(c)
			return ("%02x "):format(c:byte())
		end)
		print(caption..": "..hex.." "..bytestr)
	end]]

	readwrite(4)--printread("Sig",4)
	readwrite(1)--printread("Ver",1)
	readwrite(1)--printread("Format",1)
	readwrite(1)--printread("Endian",1)
	readwrite(1)--printread("sizeint",1)
	readwrite(1)--printread("sizesize_t",1)
	readwrite(1)--printread("sizeinstr",1)
	readwrite(1)--printread("sizeluanumber",1)
	readwrite(1)--printread("integral",1)

	local scriptData = {}
	local scriptFuncs = {}
	scriptData.Funcs = scriptFuncs
	
	local funcsRead = 0
	
	local function readFunc()
		funcsRead = funcsRead + 1
		local funcData = {}

		local srcSize = readwriteInt()
		readwrite(srcSize)
		--warn("SOURCE",srcSize)
		local lineDefined = readwriteInt()
		local lastLineDefined = readwriteInt()

		readwrite(1+1+1+1)

		local vmName = vmNameMap[lineDefined]

		local sizecode = readInt()
		write(string.pack("<I4",sizecode/2))
		--warn(vmName..": STARTING TO READ A FUNC WITH NUM INSTRS = ",sizecode)
		if not vmCounts[vmName] then error("NEW VM",lineDefined,vmName) end
		vmCounts[vmName] = vmCounts[vmName] + 1
		--print("LINE DEFINED",lineDefined)
		--print("LAST LINE DEFINED",lastLineDefined)

		local funcOps = {}

		for i = 1,sizecode/2 do
			local instrKey = read(4)
			local instrData = read(4)
			
			local instrKeyBytes = bytestring(string.pack(">I4",string.unpack("<I4",instrKey)))
			--local instrDataBytes = string.pack(">I4",string.unpack("<I4",instrData))

			local instrKeyNum = string.unpack("<I4",instrKey)
			local instrDataNum = string.unpack("<I4",instrData)

			local afterPc = i*8

			-- TODO: setlist C = 0?

			local decrypted = secdec(vmName,afterPc,instrKeyNum,instrDataNum)
			local decryptedRand = secdec(targetVM,2134,instrKeyNum,0xfafe34da)
			local decryptedRand2 = secdec(targetVM,1412,instrKeyNum,0x2ebc3405)
			--local decryptedBytes = string.pack(">I4",decrypted)
			
			if not keyToInstr[instrKeyBytes] or (decryptedRand == 0 and decryptedRand2 == 0) then
				--print("NEW KEY",instrKeyBytes,"AT",i-1,"FUNCID",funcsRead)
			end
			
			local decrypredToWrite = string.pack("<I4",decrypted)
			write(decrypredToWrite)


			--if i % 2 == 0 then instrNum = bit32.bxor(instrNum,4294967295) end

			--local op = bit32.extract(instrNum,0,6)
			--local op = bytestring(instrKeyBytes)
			--opcodeMap[op] = if opcodeMap[op] then opcodeMap[op] + 1 else 1
			--if i % 2 == 0 then continue end

			--local op = bytestring(instrKeyBytes)
			--if opcodeMap[op] then
			--	opcodeMap[op] = opcodeMap[op] + 1
			--else
			--	opcodeMap[op] = 1
			--end

			--local decdpart = ""

			--if decrypted ~= 0 then
			--	decdpart = "DEC'D:  "..bytestring(decryptedBytes)
			--end

			--print(tostring(relPc)..")","Key:",bytestring(instrKeyBytes),"Data:",bytestring(instrDataBytes),decdpart)
		end

		--local consts = {}

		local sizek = readwriteInt()
		--print("NUM CONSTS",sizek)
		for i = 1,sizek do
			local typ = readwrite(1):byte()
			if typ == 0 then
				--print("NIL")
				--table.insert(consts,"nil")
			elseif typ == 1 then
				--print("BOOL",read(1) == "\1" and "true" or "false")
				--table.insert(consts, readwrite(1) == "\1" and "true" or "false")
				readwrite(1)
			elseif typ == 3 then
				--print("LUA_NUMBER", tostring(readNumber()))
				--table.insert(consts,readwriteNumber())
				readwriteNumber()
			elseif typ == 4 then
				--local str = readString()
				--print("STR", str)
				--table.insert(consts,str:sub(1,#str-1))
				readwriteString()
			else
				error("INAVLID CONST TYPE "..tostring(typ))
			end
		end

		local sizep = readwriteInt()
		--print("NUM PROTOS",sizek)
		for i = 1,sizep do
			readFunc()
		end

		local sizeSourceLine = readwriteInt()
		--print("NUM SOURCE LINE",sizeSourceLine)
		for i = 1,sizeSourceLine do
			readwriteInt()
			--print(i,readInt())
		end

		local sizeLoc = readwriteInt()
		--print("NUM LOCALS",sizeLoc)
		for i = 1,sizeLoc do
			--print(i,readString(),readInt(),readInt())
			readwriteString()readwriteInt()readwriteInt()
		end

		local sizeUps = readwriteInt()
		--print("NUM UPVALS",sizeUps)
		for i = 1,sizeUps do
			--print(i,readString())
			readwriteString()
		end
	end

	readFunc(0)
	local re = read(#strBuffer)
	print("REMAINING DATA",#re)
	
	writefile(data.FileName.."_unsec",table.concat(writeBuffer))
	print("WROTE")
end

local function getVanillaString(instr)
	local op = bit32.extract(instr,0,6)
	local a = bit32.extract(instr,6,8)
	local c = bit32.extract(instr,14,9)
	local b = bit32.extract(instr,23,9)
	local ext = bit32.extract(instr,14,18)
	
	local str = opcodes[op+1].." "..opmodes[op+1]..": "
	
	local mode = opmodes[op+1]
	for w in mode:gmatch("%S+") do
		if w == "A" then
			str = str..a.." "
		elseif w == "B" then
			str = str..b.." "
		elseif w == "C" then
			str = str..c.." "
		elseif w == "Bx" then
			str = str..ext.." "
		elseif w == "sBx" then
			str = str..ext.." "
		end
	end
	
	return str
end

local function findAndPrintConsts(scr,findBytes)
	for i,v in pairs(scr.Data.Funcs) do
		for pc,data in pairs(v.Code) do
			local instrKey = data[1]
			local instrKeyBytes = bytestring(string.pack(">I4",string.unpack("<I4",instrKey)))
			
			if instrKeyBytes == findBytes then
				print("FOUND",instrKeyBytes,"AT",pc-1,"OF FUNC",i)
				for pc2,data in pairs(v.Code) do
					local instrKey = data[1]
					local instrKeyBytes = bytestring(string.pack(">I4",string.unpack("<I4",instrKey)))
					local instrData = data[2]
					
					local instrKeyNum = string.unpack("<I4",instrKey)
					local instrDataNum = string.unpack("<I4",instrData)

					local afterPc = pc2*8

					-- TODO: setlist C = 0?

					local decrypted = secdec(targetVM,afterPc,instrKeyNum,instrDataNum)
					local vanString = getVanillaString(decrypted)
					
					if keyToInstr[instrKeyBytes] then
						print(instrKeyBytes,vanString)
					else
						print(instrKeyBytes,"UNK",vanString)
					end
				end
				print("------------------------------------------- CONSTS")
				for i,v in pairs(v.Consts) do
					print(i,v)
				end
			end
		end
	end
end

if false then
local yup = readfile("lindec.lua")
local f = load(yup)
print(load(yup))
return
end

for i,v in pairs(scripts) do
	readScript(v)
	print("DONE",#v.Data.Funcs,"FUNCS")
end

print("DONE READING\n\n")
--[[
mapOpcodes(scripts.BenchmarkV,scripts.BenchmarkS,{
	IgnoreConsts = {["insert"] = true}
})

mapOpcodes(scripts.benchmarkoldV,scripts.benchmarkoldS)
mapOpcodes(scripts.DexV,scripts.DexS)
mapOpcodes(scripts.DexAprilV,scripts.DexAprilS)
mapOpcodes(scripts.dexold1_v,scripts.dexold1)]]

--compareSecures(scripts.Linoria1,scripts.Linoria2)

--mapOpcodes(scripts.DexV,scripts.DexOld1)

--countVanillaOps(scripts.LustrisV)

--local linoriaOps = countSecureOps(scripts.Linoria1)



--compareKeys()

--convert(scripts.DexS)

convert(scripts.newestlin)

--findAndPrintConsts(scripts.Linoria1,"00 00 48 9f ")


--compareSecures(scripts.Linoria1,scripts.Linoria2)
--compareSecures(scripts.Linoria1,scripts.Linoria2,{Func1Start = 673, Func2Start = 672})



local totalKeys = 0
for _ in pairs(keyToInstr) do totalKeys = totalKeys + 1 end
print(totalKeys,"KEYS")

--[[
for key in pairs(linoriaOps) do
	if not keyToInstr[key] then
		print("UNK",key)
	end
end
]]

--[[

local sorted = {}
local n = 0 for op,count in pairs(opcodeMap) do table.insert(sorted,{op,count}) n = n + 1 end
warn(n,"OPCODES")

table.sort(sorted,function(a,b) return a[2] < b[2] end)
for _,data in pairs(sorted) do
	--print("OPCODE",data[1],"HAS",data[2])
end

if VMSurvey then
	for i,v in pairs(vmCounts) do
		print(i,v)
	end
end
]]