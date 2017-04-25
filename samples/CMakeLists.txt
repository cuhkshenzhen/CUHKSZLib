aux_source_directory(. SAMPLE_SOURCES)
foreach(sample_source ${SAMPLE_SOURCES})
  string(REPLACE ".cpp" "" sample_bin ${sample_source})
  string(REPLACE "./" "" sample_bin ${sample_bin})
  add_executable(${sample_bin} ${sample_source})
  target_link_libraries(${sample_bin} cuhkszlib)
endforeach()
# copy EnglishWords.txt for trie
add_custom_command(
  TARGET trie POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
          ${CMAKE_SOURCE_DIR}/samples/EnglishWords.txt
          ${CMAKE_CURRENT_BINARY_DIR}/EnglishWords.txt)
