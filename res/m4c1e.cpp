    cout << "\33[H\33[2J";
    if (app_state == 0x6) return 0;
    else if (app_state == 0x9) {
      user_logged_id = -1;
      app_state = 0;
    }
    else if (user_logged_id == 0 &&
         app_state == 0x7) {
      user_logged_id = -1;
      app_state = 0;
    }
    switch (app_state & 0x1) {
      case 0: {
        unlogged_page();
      } break;
      case 1: {
        if (user_logged_id == 0) admin_page();
        else logged_page();
      } } } }
