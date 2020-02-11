
function trim(str) -- Lua doesn't have a trim function built in
    return (str:gsub("^%s*(.-)%s*$", "%1"))
end

math.randomseed(os.time()) -- Lua doesn't do this by default.
for i = 1, 100 do math.random() end -- The first few random numbers have low quality.

repeat
    print("Guess a number between 1 - 100!")
    local guess = -1
    local target = math.random(100) -- Lower bound defauls to 1

    while guess ~= target do
        io.write("Guess: ")
        -- pcall checks if it's passed function executes without any errors.
        if pcall(function() guess = math.floor(tonumber(io.read())) end) then
            if     guess < target then print("Higher!")
            elseif guess > target then print("Lower!")
            end
        else
            print("Please type a number!")
        end
    end
    print("You guessed it!")
    print("Play again?")
    io.write("(Y/n): ")
until trim(io.read()):lower():sub(1,1) == "n"
