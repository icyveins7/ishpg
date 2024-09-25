for i=3,1,-1 do
  io.write(string.format("%d\n", i))
end

print("hello from lua")

function checkStructure(args)
  if type(args.oWidth) ~= "number" then
    print("oWidth="..args.oWidth)
    error("must specify byte offset to width")
  end
  print("structure ok")

  return 0
end

checkStructure{oWidth=1}

local success, returnval = pcall(
  function()
    checkStructure{oWidth=1}
  end
)
print(success)
print(returnval)

-- cannot pcall with table input?
--local success = pcall(checkStructure{oWidth=1})
if success then
  print("test case passed")
end
