
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; Copyright (c) ....:. All rights reserved.
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(ns test.OctaneFullTest
    (:import (junit.framework Assert))            
	(:gen-class
	 :extends junit.framework.TestCase
     :methods
[    
        [ test_parse_system_args [] void]
        [ test_shell_display_loop [] void]
        [ test_get_hist_header [] void]
        [ test_serialize_object [] void]
        [ test_recent_buffer_state [] void]
        [ test_search_find_button [] void]
        [ test_regex_example_text [] void]
        [ test_hist_header_msg [] void]
        [ test_add_select_style [] void]
        [ test_init_search_helper [] void]
        [ test_set_file_state [] void]
        [ test_tab_text_4 [] void]
        [ test_search_shell [] void]
        [ test_create_graphs_menu [] void]
        [ test_tab_text_3 [] void]
        [ test_init_colors [] void]
        [ test_deserialize_object [] void]
        [ test_tab_text_2 [] void]
        [ test_get_findgrep_widg_state [] void]
        [ test_history_add_textln [] void]
        [ test_prop_core_sys [] void]
        [ test_regex_match_style [] void]
        [ test_regex_edit_box [] void]
        [ test_search_composite [] void]
        [ test_build_findgrep_arr [] void]
        [ test_styled_text_font [] void]
        [ test_open_file_listener [] void]
        [ test_set_directory_open [] void]
        [ test_search_box [] void]
        [ test_table_col_names [] void]
        [ test_tab_folder [] void]
        [ test_loop_db_files [] void]
        [ test_create_search_dialog [] void]
        [ test_regex_match_group [] void]
        [ test_file_last_mod [] void]
        [ test_shell_close_listener [] void]
        [ test_start_filemanager_proc [] void]
        [ test_serialize_object_1 [] void]
        [ test_open_file_util [] void]
        [ test_rcol_vec_bg [] void]
        [ test_regex_colors_vec [] void]
        [ test_recent_menu_listener [] void]
        [ test_red_color [] void]
        [ test_get_buffer_menu_state [] void]
        [ test_resources_user [] void]
        [ test_example_regex_document [] void]
        [ test_green_color [] void]
        [ test_println_obj [] void]
        [ test_create_recent_menu_items [] void]
        [ test_resources_win_opts [] void]
        [ test_create_file_menu [] void]
        [ test_format_has_val [] void]
        [ test_col_vec_grey [] void]
        [ test_refresh_regex_example [] void]
        [ test_history_add_text [] void]
        [ test_db_filter_box [] void]
        [ test_set_buffer_menu_state [] void]
        [ test_save_file_list [] void]
        [ test_col_vec_drkb [] void]
        [ test_tab_area_3 [] void]
        [ test_tab_area_4 [] void]
        [ test_set_findgrep_widg_state [] void]
        [ test_regex_style_listener [] void]
        [ test_findgrep_widg_state [] void]
        [ test_tab_area_2 [] void]
        [ test_clear_buffer [] void]
        [ test_rcol_vec_grey [] void]
        [ test_regex_shell [] void]
        [ test_open_directory [] void]
        [ test_find_text_listener [] void]
        [ test_create_grid_layout [] void]
        [ test_async_status_history [] void]
        [ test_style_handler [] void]
        [ test_tab_area_1 [] void]
        [ test_prop_bool [] void]
        [ test_create_status_bar [] void]
        [ test_rcol_vec_cy [] void]
        [ test_when_try [] void]
        [ test_directory_dialog [] void]
        [ test_load_file_list [] void]
        [ test_get_current_dir [] void]
        [ test_recent_buffer_listener [] void]
        [ test_display [] void]
        [ test_add_main_text [] void]
        [ test_db_filtersrv_button [] void]
        [ test_main_match_style [] void]
        [ test_regex_style_handler [] void]
        [ test_location_bar [] void]
        [ test_init_regex_helper [] void]
        [ test_db_button_comp [] void]
        [ test_octane_pattern [] void]
        [ test_set_curfile_open [] void]
        [ test_open_file_or_dir [] void]
        [ test_resources_core_sys [] void]
        [ test_get_current_dirquote [] void]
        [ test_init_gui_helper [] void]
        [ test_create_regex_grid_layout [] void]
        [ test_prop_str [] void]
        [ test_tab_4_title [] void]
        [ test_create_search_grid_layout [] void]
        [ test_set_recent_file_table [] void]
        [ test_file_info_msg [] void]
        [ test_create_search_menu [] void]
        [ test_add_table_item [] void]
        [ test_search_keyword [] void]
        [ test_octane_pattern_ [] void]
        [ test_database_shell [] void]
        [ test_get_process [] void]
        [ test_get_file_last_mod [] void]
        [ test_cur_file_info [] void]
        [ test_tab_2_title [] void]
        [ test_file_exists? [] void]
        [ test_style_keyword_match [] void]
        [ test_date_time [] void]
        [ test_win_size_width [] void]
        [ test_main_generate_test_cases [] void]
        [ test_rcol_vec_wht [] void]
        [ test_floor [] void]
        [ test_add_findgrep_options [] void]
        [ test_col_vec_bg [] void]
        [ test_format_db_button_listener [] void]
        [ test_get_last_file_path [] void]
        [ test_format_isdir_name [] void]
        [ test_lightgrey_color [] void]
        [ test_col_vec_red [] void]
        [ test_srchbox_get_text [] void]
        [ test_regex_get_text [] void]
        [ test_regex_search_keyword [] void]
        [ test_create_analytics_menu [] void]
        [ test_date_timel [] void]
        [ test_colors_vec [] void]
        [ test_async_add_text [] void]
        [ test_on_file_open [] void]
        [ test_load_default_database [] void]
        [ test_find_regex_listener [] void]
        [ test_refresh_textarea_deprecated [] void]
        [ test_regex_search_term? [] void]
        [ test_add_text_buffer [] void]
        [ test_set_file_info [] void]
        [ test_resources_win [] void]
        [ test_async_call [] void]
        [ test_get_findgrep_helper [] void]
        [ test_search_label [] void]
        [ test_get_install_dir_1 [] void]
        [ test_create_all_tabs [] void]
        [ test_buffer_3 [] void]
        [ test_add_items_db_view [] void]
        [ test_table_select_listener [] void]
        [ test_create_database_window [] void]
        [ test_col_vec_cy [] void]
        [ test_length [] void]
        [ test_location_text_listener [] void]
        [ test_deserialize_object_1 [] void]
        [ test_styled_text [] void]
        [ test_create_help_menu [] void]
        [ test_create_regex_window [] void]
        [ test_dialog_open_file [] void]
        [ test_create_menu_item [] void]
        [ test_dark_blue_color [] void]
        [ test_col_vec_wht [] void]
        [ test_shell [] void]
        [ test_display_error [] void]
        [ test_get_install_dir [] void]
        [ test_init_buttons_composite [] void]
        [ test_buffer_1 [] void]
        [ test_create_gui_window [] void]
        [ test_create_db_grid_layout [] void]
        [ test_status_set_text [] void]
        [ test_proc_time [] void]
        [ test_fileDialog [] void]
        [ test_rcol_vec_red [] void]
        [ test_create_styled_text_area [] void]
        [ test_white_color [] void]
        [ test_buffer_2 [] void]
        [ test_findgrep_listener [] void]
        [ test_get_directory_open [] void]
        [ test_run_codegen_build_xml [] void]
        [ test_refresh_textarea [] void]
        [ test_prop_core_sys_int [] void]
        [ test_print_test_case [] void]
        [ test_db_filtergrp_button [] void]
        [ test_create_menu_bar [] void]
        [ test_db_file_table [] void]
        [ test_file_state [] void]
        [ test_status_arm_listener [] void]
        [ test_create_database_table [] void]
        [ test_get_file_state [] void]
        [ test_async_status_text [] void]
        [ test_add_main_text_nc [] void]
        [ test_run_findgrep_widget [] void]
        [ test_regex_label [] void]
        [ test_init_database_helper [] void]
        [ test_prop_core_sys_bool [] void]
        [ test_create_tab_2 [] void]
        [ test_swt_text_style [] void]
        [ test_swt_tabtext_style [] void]
        [ test_search_term? [] void]
        [ test_recent_menu_state [] void]
        [ test_add_recent_file [] void]
        [ test_create_tools_menu [] void]
        [ test_dialog_open_dir [] void]
        [ test_db_totext_button [] void]
        [ test_win_size_height [] void]
        [ test_create_tab_1 [] void]
        [ test_file_monitor_loop [] void]
        [ test_recent_file_table [] void]
        [ test_db_search_box [] void]
        [ test_format_db_table [] void]
        [ test_create_about_messagebox [] void]
        [ test_set_file_last_mod [] void]
        [ test_add_recent_buffer_menu [] void]
        [ test_search_filter_box [] void]
        [ test_orange_sel_color [] void]
        [ test_cyan_sel_color [] void]
        [ test_rcol_vec_drkb [] void]
        [ test_create_regex_styled_text [] void]
        [ test_location_set_text [] void]
        [ test_start_findgrep_cmd [] void]
        [ test_buffer_menu_state [] void]
        [ test_start_findgrep_thread [] void]
        [ test_style_listener [] void]
        [ test_init_regex_colors [] void]
        [ test_exit [] void]
        [ test_start_process [] void]
        [ test_get_file_info_header [] void]
        [ test_format_dir_file [] void]
        [ test_get_curfile_open [] void]
        [ test_prop_int [] void]
        [ test_get_dir_date [] void]
        [ test_get_recent_file_table [] void]
        [ test_start_findgrep_thread_java [] void]
		[ test_prototype_cmd_line_db [] void ]
 ]))

(defn -init [_] ()) 
	
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Simple prototype test for string split
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn 

;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "parse_system_args"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_parse_system_args [_]
  (Assert/fail "Test not implemented (parse_system_args)" ))
    
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "shell_display_loop"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_shell_display_loop [_]
  (Assert/fail "Test not implemented (shell_display_loop)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "get_hist_header"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_get_hist_header [_]
  (Assert/fail "Test not implemented (get_hist_header)" ))
    
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "serialize_object"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_serialize_object [_]
  (Assert/fail "Test not implemented (serialize_object)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "recent_buffer_state"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_recent_buffer_state [_]
  (Assert/fail "Test not implemented (recent_buffer_state)" ))
    
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "search_find_button"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_search_find_button [_]
  (Assert/fail "Test not implemented (search_find_button)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "regex_example_text"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_regex_example_text [_]
  (Assert/fail "Test not implemented (regex_example_text)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "hist_header_msg"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_hist_header_msg [_]
  (Assert/fail "Test not implemented (hist_header_msg)" ))
    
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "add_select_style"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_add_select_style [_]
  (Assert/fail "Test not implemented (add_select_style)" ))
    
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "init_search_helper"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_init_search_helper [_]
  (Assert/fail "Test not implemented (init_search_helper)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "set_file_state"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_set_file_state [_]
  (Assert/fail "Test not implemented (set_file_state)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "tab_text_4"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_tab_text_4 [_]
  (Assert/fail "Test not implemented (tab_text_4)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "search_shell"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_search_shell [_]
  (Assert/fail "Test not implemented (search_shell)" ))
 
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "create_graphs_menu"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_create_graphs_menu [_]
  (Assert/fail "Test not implemented (create_graphs_menu)" ))
    
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "tab_text_3"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_tab_text_3 [_]
  (Assert/fail "Test not implemented (tab_text_3)" ))
    
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "init_colors"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_init_colors [_]
  (Assert/fail "Test not implemented (init_colors)" ))
    
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "deserialize_object"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_deserialize_object [_]
  (Assert/fail "Test not implemented (deserialize_object)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "tab_text_2"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_tab_text_2 [_]
  (Assert/fail "Test not implemented (tab_text_2)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "get_findgrep_widg_state"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_get_findgrep_widg_state [_]
  (Assert/fail "Test not implemented (get_findgrep_widg_state)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "history_add_textln"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_history_add_textln [_]
  (Assert/fail "Test not implemented (history_add_textln)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "prop_core_sys"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_prop_core_sys [_]
  (Assert/fail "Test not implemented (prop_core_sys)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "regex_match_style"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_regex_match_style [_]
  (Assert/fail "Test not implemented (regex_match_style)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "regex_edit_box"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_regex_edit_box [_]
  (Assert/fail "Test not implemented (regex_edit_box)" ))
    
    
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "search_composite"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_search_composite [_]
  (Assert/fail "Test not implemented (search_composite)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "build_findgrep_arr"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_build_findgrep_arr [_]
  (Assert/fail "Test not implemented (build_findgrep_arr)" ))
    
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "styled_text_font"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_styled_text_font [_]
  (Assert/fail "Test not implemented (styled_text_font)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "open_file_listener"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_open_file_listener [_]
  (Assert/fail "Test not implemented (open_file_listener)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "set_directory_open"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_set_directory_open [_]
  (Assert/fail "Test not implemented (set_directory_open)" ))
    
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "search_box"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_search_box [_]
  (Assert/fail "Test not implemented (search_box)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "table_col_names"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_table_col_names [_]
  (Assert/fail "Test not implemented (table_col_names)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "tab_folder"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_tab_folder [_]
  (Assert/fail "Test not implemented (tab_folder)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "loop_db_files"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_loop_db_files [_]
  (Assert/fail "Test not implemented (loop_db_files)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "create_search_dialog"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_create_search_dialog [_]
  (Assert/fail "Test not implemented (create_search_dialog)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "regex_match_group"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_regex_match_group [_]
  (Assert/fail "Test not implemented (regex_match_group)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "file_last_mod"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_file_last_mod [_]
  (Assert/fail "Test not implemented (file_last_mod)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "shell_close_listener"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_shell_close_listener [_]
  (Assert/fail "Test not implemented (shell_close_listener)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "start_filemanager_proc"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_start_filemanager_proc [_]
  (Assert/fail "Test not implemented (start_filemanager_proc)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "serialize_object_1"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_serialize_object_1 [_]
  (Assert/fail "Test not implemented (serialize_object_1)" ))
    
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "open_file_util"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_open_file_util [_]
  (Assert/fail "Test not implemented (open_file_util)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "rcol_vec_bg"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_rcol_vec_bg [_]
  (Assert/fail "Test not implemented (rcol_vec_bg)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "regex_colors_vec"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_regex_colors_vec [_]
  (Assert/fail "Test not implemented (regex_colors_vec)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "recent_menu_listener"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_recent_menu_listener [_]
  (Assert/fail "Test not implemented (recent_menu_listener)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "red_color"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_red_color [_]
  (Assert/fail "Test not implemented (red_color)" ))
    
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "get_buffer_menu_state"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_get_buffer_menu_state [_]
  (Assert/fail "Test not implemented (get_buffer_menu_state)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "resources_user"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_resources_user [_]
  (Assert/fail "Test not implemented (resources_user)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "example_regex_document"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_example_regex_document [_]
  (Assert/fail "Test not implemented (example_regex_document)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "green_color"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_green_color [_]
  (Assert/fail "Test not implemented (green_color)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "println_obj"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_println_obj [_]
  (Assert/fail "Test not implemented (println_obj)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "create_recent_menu_items"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_create_recent_menu_items [_]
  (Assert/fail "Test not implemented (create_recent_menu_items)" ))
    
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "resources_win_opts"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_resources_win_opts [_]
  (Assert/fail "Test not implemented (resources_win_opts)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "create_file_menu"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_create_file_menu [_]
  (Assert/fail "Test not implemented (create_file_menu)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "format_has_val"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_format_has_val [_]
  (Assert/fail "Test not implemented (format_has_val)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "col_vec_grey"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_col_vec_grey [_]
  (Assert/fail "Test not implemented (col_vec_grey)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "refresh_regex_example"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_refresh_regex_example [_]
  (Assert/fail "Test not implemented (refresh_regex_example)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "history_add_text"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_history_add_text [_]
  (Assert/fail "Test not implemented (history_add_text)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "db_filter_box"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_db_filter_box [_]
  (Assert/fail "Test not implemented (db_filter_box)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "set_buffer_menu_state"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_set_buffer_menu_state [_]
  (Assert/fail "Test not implemented (set_buffer_menu_state)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "save_file_list"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_save_file_list [_]
  (Assert/fail "Test not implemented (save_file_list)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "col_vec_drkb"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_col_vec_drkb [_]
  (Assert/fail "Test not implemented (col_vec_drkb)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "tab_area_3"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_tab_area_3 [_]
  (Assert/fail "Test not implemented (tab_area_3)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "tab_area_4"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_tab_area_4 [_]
  (Assert/fail "Test not implemented (tab_area_4)" ))
    
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "set_findgrep_widg_state"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_set_findgrep_widg_state [_]
  (Assert/fail "Test not implemented (set_findgrep_widg_state)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "regex_style_listener"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_regex_style_listener [_]
  (Assert/fail "Test not implemented (regex_style_listener)" ))
  
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "findgrep_widg_state"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_findgrep_widg_state [_]
  (Assert/fail "Test not implemented (findgrep_widg_state)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "tab_area_2"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_tab_area_2 [_]
  (Assert/fail "Test not implemented (tab_area_2)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "clear_buffer"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_clear_buffer [_]
  (Assert/fail "Test not implemented (clear_buffer)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "rcol_vec_grey"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_rcol_vec_grey [_]
  (Assert/fail "Test not implemented (rcol_vec_grey)" ))
  
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "regex_shell"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_regex_shell [_]
  (Assert/fail "Test not implemented (regex_shell)" ))
    
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "open_directory"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_open_directory [_]
  (Assert/fail "Test not implemented (open_directory)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "find_text_listener"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_find_text_listener [_]
  (Assert/fail "Test not implemented (find_text_listener)" ))
    
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "create_grid_layout"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_create_grid_layout [_]
  (Assert/fail "Test not implemented (create_grid_layout)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "async_status_history"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_async_status_history [_]
  (Assert/fail "Test not implemented (async_status_history)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "style_handler"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_style_handler [_]
  (Assert/fail "Test not implemented (style_handler)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "tab_area_1"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_tab_area_1 [_]
  (Assert/fail "Test not implemented (tab_area_1)" ))
  

;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "prop_bool"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_prop_bool [_]
  (Assert/fail "Test not implemented (prop_bool)" ))
    
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "create_status_bar"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_create_status_bar [_]
  (Assert/fail "Test not implemented (create_status_bar)" ))
    
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "rcol_vec_cy"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_rcol_vec_cy [_]
  (Assert/fail "Test not implemented (rcol_vec_cy)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "when_try"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_when_try [_]
  (Assert/fail "Test not implemented (when_try)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "directory_dialog"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_directory_dialog [_]
  (Assert/fail "Test not implemented (directory_dialog)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "load_file_list"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_load_file_list [_]
  (Assert/fail "Test not implemented (load_file_list)" ))
    
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "get_current_dir"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_get_current_dir [_]
  (Assert/fail "Test not implemented (get_current_dir)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "recent_buffer_listener"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_recent_buffer_listener [_]
  (Assert/fail "Test not implemented (recent_buffer_listener)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "display"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_display [_]
  (Assert/fail "Test not implemented (display)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "add_main_text"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_add_main_text [_]
  (Assert/fail "Test not implemented (add_main_text)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "db_filtersrv_button"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_db_filtersrv_button [_]
  (Assert/fail "Test not implemented (db_filtersrv_button)" ))
  
    
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "main_match_style"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_main_match_style [_]
  (Assert/fail "Test not implemented (main_match_style)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "regex_style_handler"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_regex_style_handler [_]
  (Assert/fail "Test not implemented (regex_style_handler)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "location_bar"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_location_bar [_]
  (Assert/fail "Test not implemented (location_bar)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "init_regex_helper"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_init_regex_helper [_]
  (Assert/fail "Test not implemented (init_regex_helper)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "db_button_comp"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_db_button_comp [_]
  (Assert/fail "Test not implemented (db_button_comp)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "octane_pattern"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_octane_pattern [_]
  (Assert/fail "Test not implemented (octane_pattern)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "set_curfile_open"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_set_curfile_open [_]
  (Assert/fail "Test not implemented (set_curfile_open)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "open_file_or_dir"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_open_file_or_dir [_]
  (Assert/fail "Test not implemented (open_file_or_dir)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "resources_core_sys"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_resources_core_sys [_]
  (Assert/fail "Test not implemented (resources_core_sys)" ))
    
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "get_current_dirquote"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_get_current_dirquote [_]
  (Assert/fail "Test not implemented (get_current_dirquote)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "init_gui_helper"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_init_gui_helper [_]
  (Assert/fail "Test not implemented (init_gui_helper)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "create_regex_grid_layout"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_create_regex_grid_layout [_]
  (Assert/fail "Test not implemented (create_regex_grid_layout)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "prop_str"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_prop_str [_]
  (Assert/fail "Test not implemented (prop_str)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "tab_4_title"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_tab_4_title [_]
  (Assert/fail "Test not implemented (tab_4_title)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "create_search_grid_layout"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_create_search_grid_layout [_]
  (Assert/fail "Test not implemented (create_search_grid_layout)" ))
  
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "set_recent_file_table"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_set_recent_file_table [_]
  (Assert/fail "Test not implemented (set_recent_file_table)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "file_info_msg"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_file_info_msg [_]
  (Assert/fail "Test not implemented (file_info_msg)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "create_search_menu"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_create_search_menu [_]
  (Assert/fail "Test not implemented (create_search_menu)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "add_table_item"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_add_table_item [_]
  (Assert/fail "Test not implemented (add_table_item)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "search_keyword"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_search_keyword [_]
  (Assert/fail "Test not implemented (search_keyword)" ))
      
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "octane_pattern_"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_octane_pattern_ [_]
  (Assert/fail "Test not implemented (octane_pattern_)" ))
    
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "database_shell"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_database_shell [_]
  (Assert/fail "Test not implemented (database_shell)" ))
    
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "get_process"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_get_process [_]
  (Assert/fail "Test not implemented (get_process)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "get_file_last_mod"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_get_file_last_mod [_]
  (Assert/fail "Test not implemented (get_file_last_mod)" ))
  
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "cur_file_info"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_cur_file_info [_]
  (Assert/fail "Test not implemented (cur_file_info)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "tab_2_title"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_tab_2_title [_]
  (Assert/fail "Test not implemented (tab_2_title)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "file_exists?"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_file_exists? [_]
  (Assert/fail "Test not implemented (file_exists?)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "style_keyword_match"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_style_keyword_match [_]
  (Assert/fail "Test not implemented (style_keyword_match)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "date_time"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_date_time [_]
  (Assert/fail "Test not implemented (date_time)" ))
    
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "win_size_width"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_win_size_width [_]
  (Assert/fail "Test not implemented (win_size_width)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "main_generate_test_cases"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_main_generate_test_cases [_]
  (Assert/fail "Test not implemented (main_generate_test_cases)" ))
    
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "rcol_vec_wht"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_rcol_vec_wht [_]
  (Assert/fail "Test not implemented (rcol_vec_wht)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "floor"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_floor [_]
  (Assert/fail "Test not implemented (floor)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "add_findgrep_options"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_add_findgrep_options [_]
  (Assert/fail "Test not implemented (add_findgrep_options)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "col_vec_bg"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_col_vec_bg [_]
  (Assert/fail "Test not implemented (col_vec_bg)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "format_db_button_listener"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_format_db_button_listener [_]
  (Assert/fail "Test not implemented (format_db_button_listener)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "get_last_file_path"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_get_last_file_path [_]
  (Assert/fail "Test not implemented (get_last_file_path)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "format_isdir_name"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_format_isdir_name [_]
  (Assert/fail "Test not implemented (format_isdir_name)" ))
    
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "lightgrey_color"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_lightgrey_color [_]
  (Assert/fail "Test not implemented (lightgrey_color)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "col_vec_red"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_col_vec_red [_]
  (Assert/fail "Test not implemented (col_vec_red)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "srchbox_get_text"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_srchbox_get_text [_]
  (Assert/fail "Test not implemented (srchbox_get_text)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "regex_get_text"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_regex_get_text [_]
  (Assert/fail "Test not implemented (regex_get_text)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "regex_search_keyword"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_regex_search_keyword [_]
  (Assert/fail "Test not implemented (regex_search_keyword)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "create_analytics_menu"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_create_analytics_menu [_]
  (Assert/fail "Test not implemented (create_analytics_menu)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "date_timel"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_date_timel [_]
  (Assert/fail "Test not implemented (date_timel)" ))
  
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "colors_vec"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_colors_vec [_]
  (Assert/fail "Test not implemented (colors_vec)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "async_add_text"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_async_add_text [_]
  (Assert/fail "Test not implemented (async_add_text)" ))
    
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "on_file_open"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_on_file_open [_]
  (Assert/fail "Test not implemented (on_file_open)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "load_default_database"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_load_default_database [_]
  (Assert/fail "Test not implemented (load_default_database)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "find_regex_listener"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_find_regex_listener [_]
  (Assert/fail "Test not implemented (find_regex_listener)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "refresh_textarea_deprecated"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_refresh_textarea_deprecated [_]
  (Assert/fail "Test not implemented (refresh_textarea_deprecated)" ))
  
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "regex_search_term?"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_regex_search_term? [_]
  (Assert/fail "Test not implemented (regex_search_term?)" ))
    
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "add_text_buffer"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_add_text_buffer [_]
  (Assert/fail "Test not implemented (add_text_buffer)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "set_file_info"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_set_file_info [_]
  (Assert/fail "Test not implemented (set_file_info)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "resources_win"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_resources_win [_]
  (Assert/fail "Test not implemented (resources_win)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "async_call"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_async_call [_]
  (Assert/fail "Test not implemented (async_call)" ))
    
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "get_findgrep_helper"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_get_findgrep_helper [_]
  (Assert/fail "Test not implemented (get_findgrep_helper)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "search_label"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_search_label [_]
  (Assert/fail "Test not implemented (search_label)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "get_install_dir_1"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_get_install_dir_1 [_]
  (Assert/fail "Test not implemented (get_install_dir_1)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "create_all_tabs"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_create_all_tabs [_]
  (Assert/fail "Test not implemented (create_all_tabs)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "buffer_3"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_buffer_3 [_]
  (Assert/fail "Test not implemented (buffer_3)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "add_items_db_view"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_add_items_db_view [_]
  (Assert/fail "Test not implemented (add_items_db_view)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "table_select_listener"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_table_select_listener [_]
  (Assert/fail "Test not implemented (table_select_listener)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "create_database_window"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_create_database_window [_]
  (Assert/fail "Test not implemented (create_database_window)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "col_vec_cy"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_col_vec_cy [_]
  (Assert/fail "Test not implemented (col_vec_cy)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "length"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_length [_]
  (Assert/fail "Test not implemented (length)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "location_text_listener"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_location_text_listener [_]
  (Assert/fail "Test not implemented (location_text_listener)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "deserialize_object_1"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_deserialize_object_1 [_]
  (Assert/fail "Test not implemented (deserialize_object_1)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "styled_text"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_styled_text [_]
  (Assert/fail "Test not implemented (styled_text)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "create_help_menu"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_create_help_menu [_]
  (Assert/fail "Test not implemented (create_help_menu)" ))
    
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "create_regex_window"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_create_regex_window [_]
  (Assert/fail "Test not implemented (create_regex_window)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "dialog_open_file"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_dialog_open_file [_]
  (Assert/fail "Test not implemented (dialog_open_file)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "create_menu_item"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_create_menu_item [_]
  (Assert/fail "Test not implemented (create_menu_item)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "dark_blue_color"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_dark_blue_color [_]
  (Assert/fail "Test not implemented (dark_blue_color)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "col_vec_wht"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_col_vec_wht [_]
  (Assert/fail "Test not implemented (col_vec_wht)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "shell"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_shell [_]
  (Assert/fail "Test not implemented (shell)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "display_error"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_display_error [_]
  (Assert/fail "Test not implemented (display_error)" ))
    
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "get_install_dir"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_get_install_dir [_]
  (Assert/fail "Test not implemented (get_install_dir)" ))
  
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "init_buttons_composite"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_init_buttons_composite [_]
  (Assert/fail "Test not implemented (init_buttons_composite)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "buffer_1"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_buffer_1 [_]
  (Assert/fail "Test not implemented (buffer_1)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "create_gui_window"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_create_gui_window [_]
  (Assert/fail "Test not implemented (create_gui_window)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "create_db_grid_layout"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_create_db_grid_layout [_]
  (Assert/fail "Test not implemented (create_db_grid_layout)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "status_set_text"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_status_set_text [_]
  (Assert/fail "Test not implemented (status_set_text)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "proc_time"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_proc_time [_]
  (Assert/fail "Test not implemented (proc_time)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "fileDialog"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_fileDialog [_]
  (Assert/fail "Test not implemented (fileDialog)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "rcol_vec_red"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_rcol_vec_red [_]
  (Assert/fail "Test not implemented (rcol_vec_red)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "create_styled_text_area"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_create_styled_text_area [_]
  (Assert/fail "Test not implemented (create_styled_text_area)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "white_color"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_white_color [_]
  (Assert/fail "Test not implemented (white_color)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "buffer_2"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_buffer_2 [_]
  (Assert/fail "Test not implemented (buffer_2)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "findgrep_listener"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_findgrep_listener [_]
  (Assert/fail "Test not implemented (findgrep_listener)" ))
      
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "get_directory_open"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_get_directory_open [_]
  (Assert/fail "Test not implemented (get_directory_open)" ))
    
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "run_codegen_build_xml"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_run_codegen_build_xml [_]
  (Assert/fail "Test not implemented (run_codegen_build_xml)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "refresh_textarea"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_refresh_textarea [_]
  (Assert/fail "Test not implemented (refresh_textarea)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "prop_core_sys_int"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_prop_core_sys_int [_]
  (Assert/fail "Test not implemented (prop_core_sys_int)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "print_test_case"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_print_test_case [_]
  (Assert/fail "Test not implemented (print_test_case)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "db_filtergrp_button"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_db_filtergrp_button [_]
  (Assert/fail "Test not implemented (db_filtergrp_button)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "create_menu_bar"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_create_menu_bar [_]
  (Assert/fail "Test not implemented (create_menu_bar)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "db_file_table"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_db_file_table [_]
  (Assert/fail "Test not implemented (db_file_table)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "file_state"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_file_state [_]
  (Assert/fail "Test not implemented (file_state)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "status_arm_listener"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_status_arm_listener [_]
  (Assert/fail "Test not implemented (status_arm_listener)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "create_database_table"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_create_database_table [_]
  (Assert/fail "Test not implemented (create_database_table)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "get_file_state"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_get_file_state [_]
  (Assert/fail "Test not implemented (get_file_state)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "async_status_text"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_async_status_text [_]
  (Assert/fail "Test not implemented (async_status_text)" ))
    
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "add_main_text_nc"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_add_main_text_nc [_]
  (Assert/fail "Test not implemented (add_main_text_nc)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "run_findgrep_widget"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_run_findgrep_widget [_]
  (Assert/fail "Test not implemented (run_findgrep_widget)" ))
      
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "regex_label"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_regex_label [_]
  (Assert/fail "Test not implemented (regex_label)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "init_database_helper"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_init_database_helper [_]
  (Assert/fail "Test not implemented (init_database_helper)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "prop_core_sys_bool"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_prop_core_sys_bool [_]
  (Assert/fail "Test not implemented (prop_core_sys_bool)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "create_tab_2"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_create_tab_2 [_]
  (Assert/fail "Test not implemented (create_tab_2)" ))
  
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "swt_text_style"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_swt_text_style [_]
  (Assert/fail "Test not implemented (swt_text_style)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "swt_tabtext_style"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_swt_tabtext_style [_]
  (Assert/fail "Test not implemented (swt_tabtext_style)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "search_term?"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_search_term? [_]
  (Assert/fail "Test not implemented (search_term?)" ))
      
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "recent_menu_state"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_recent_menu_state [_]
  (Assert/fail "Test not implemented (recent_menu_state)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "add_recent_file"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_add_recent_file [_]
  (Assert/fail "Test not implemented (add_recent_file)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "create_tools_menu"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_create_tools_menu [_]
  (Assert/fail "Test not implemented (create_tools_menu)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "dialog_open_dir"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_dialog_open_dir [_]
  (Assert/fail "Test not implemented (dialog_open_dir)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "db_totext_button"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_db_totext_button [_]
  (Assert/fail "Test not implemented (db_totext_button)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "win_size_height"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_win_size_height [_]
  (Assert/fail "Test not implemented (win_size_height)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "create_tab_1"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_create_tab_1 [_]
  (Assert/fail "Test not implemented (create_tab_1)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "file_monitor_loop"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_file_monitor_loop [_]
  (Assert/fail "Test not implemented (file_monitor_loop)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "recent_file_table"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_recent_file_table [_]
  (Assert/fail "Test not implemented (recent_file_table)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "db_search_box"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_db_search_box [_]
  (Assert/fail "Test not implemented (db_search_box)" ))
    
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "format_db_table"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_format_db_table [_]
  (Assert/fail "Test not implemented (format_db_table)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "create_about_messagebox"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_create_about_messagebox [_]
  (Assert/fail "Test not implemented (create_about_messagebox)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "set_file_last_mod"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_set_file_last_mod [_]
  (Assert/fail "Test not implemented (set_file_last_mod)" ))
    
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "add_recent_buffer_menu"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_add_recent_buffer_menu [_]
  (Assert/fail "Test not implemented (add_recent_buffer_menu)" ))
    
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "search_filter_box"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_search_filter_box [_]
  (Assert/fail "Test not implemented (search_filter_box)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "orange_sel_color"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_orange_sel_color [_]
  (Assert/fail "Test not implemented (orange_sel_color)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "cyan_sel_color"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_cyan_sel_color [_]
  (Assert/fail "Test not implemented (cyan_sel_color)" ))
    
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "rcol_vec_drkb"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_rcol_vec_drkb [_]
  (Assert/fail "Test not implemented (rcol_vec_drkb)" ))
    
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "create_regex_styled_text"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_create_regex_styled_text [_]
  (Assert/fail "Test not implemented (create_regex_styled_text)" ))
    
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "location_set_text"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_location_set_text [_]
  (Assert/fail "Test not implemented (location_set_text)" ))
    
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "start_findgrep_cmd"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_start_findgrep_cmd [_]
  (Assert/fail "Test not implemented (start_findgrep_cmd)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "buffer_menu_state"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_buffer_menu_state [_]
  (Assert/fail "Test not implemented (buffer_menu_state)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "start_findgrep_thread"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_start_findgrep_thread [_]
  (Assert/fail "Test not implemented (start_findgrep_thread)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "style_listener"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_style_listener [_]
  (Assert/fail "Test not implemented (style_listener)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "init_regex_colors"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_init_regex_colors [_]
  (Assert/fail "Test not implemented (init_regex_colors)" ))
   
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "exit"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_exit [_]
  (Assert/fail "Test not implemented (exit)" ))
    
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "start_process"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_start_process [_]
  (Assert/fail "Test not implemented (start_process)" ))
    
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "get_file_info_header"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_get_file_info_header [_]
  (Assert/fail "Test not implemented (get_file_info_header)" ))
      
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "format_dir_file"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_format_dir_file [_]
  (Assert/fail "Test not implemented (format_dir_file)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "get_curfile_open"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_get_curfile_open [_]
  (Assert/fail "Test not implemented (get_curfile_open)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "prop_int"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_prop_int [_]
  (Assert/fail "Test not implemented (prop_int)" ))  
    
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "get_dir_date"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_get_dir_date [_]
  (Assert/fail "Test not implemented (get_dir_date)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "get_recent_file_table"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_get_recent_file_table [_]
  (Assert/fail "Test not implemented (get_recent_file_table)" ))
  
;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "start_findgrep_thread_java"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_start_findgrep_thread_java [_]
  (Assert/fail "Test not implemented (start_findgrep_thread_java)" ))

;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test case for "parse_system_args"
;;;;;;;;;;;;;;;;;;;;;;;;;
(defn -test_prototype_cmd_line_db [_]
  (let [a " abc , 123 ; uuu , ggg"
		  b (. a split ";")]
	(Assert/assertTrue (str "-test_prototype_cmd_line_db - simple proto split")
					   (> (count b) 0))
	(doseq [i b]
		(let [c (. i split ",")
				d (. (first c) trim)
				e (. (second c) trim)]
		  (Assert/assertTrue "-test_prototype_cmd_line_db" 
							 (or (= d "abc") (= d "uuu")))))))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; End of Test Case
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

