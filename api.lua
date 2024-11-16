--[[ An array of strings that contain what letters are in your language. Can include digraphs, or multiple characters for one sound. ]]
---@class Phonology

--[[ Creates a new Phonology in your language database. ]]
---@param name string
---@param phonology Phonology
new_phonology = function(name, phonology) end

--[[
    Interface with LUA and scribe software.
    <br>
    VERSION 2
]]
Scribe = {}

--[[
    Interface with LUA and the phonology section.
    <br>
    VERSION 2
]]
Scribe.Phonology = {}

--[[
    Create a new phonology.
    <br>
    VERSION 2
]]
---@param name string
---@param phonology Phonology
Scribe.Phonology.new = function(name, phonology) end

--[[
    Interface with the LUA and the LEXICON section.
    <br>
    VERSION 2
]]
Scribe.Lexicon = {}
