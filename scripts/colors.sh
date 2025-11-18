#! /usr/bin/env bash

# Control Sequence Introducer (CSI) bytes.
csi="$(printf '\e[')"

# Select Graphics Rendition (SGR) functions.
text_foreground_color="${csi}38;5;%dm"
text_background_color="${csi}48;5;%dm"
color_reset="${csi}0m"

# Specific function calls.
text_foreground_color_white="$(printf "${text_foreground_color}" "231")"
text_foreground_color_black="$(printf "${text_foreground_color}" "232")"

# Print the colors.
for i in {0..255}
do
    text_background_color_i="$(printf "${text_background_color}" "${i}")"
    printf "${text_background_color_i}${text_foreground_color_white}%03d ${text_foreground_color_black}%03d${color_reset}" "${i}" "${i}"
    printf " "

    if ((( i < 16 )) && (( i % 8 == 7 ))) || ((( i > 15 )) && (( (i-15) % 6 == 0 )))
    then
        printf "\n";
    fi
done
