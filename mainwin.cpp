#include "mainwin.h"
#include <ctime>
#include <iostream>
#include <string>

Mainwin::Mainwin() : filename{"untitled.smart"}, curr_year{current_year()} {

    // /////////////////
    // G U I   S E T U P
    // /////////////////

    set_default_size(800, 400);
    set_title("SMART");

    // Put a vertical box container as the Window contents
    Gtk::Box *vbox = Gtk::manage(new Gtk::VBox);
    add(*vbox);

    // /////// ////////////////////////////////////////////////////////////////
    // M E N U
    // Add a menu bar as the top item in the vertical box
    Gtk::MenuBar *menubar = Gtk::manage(new Gtk::MenuBar);
    vbox->pack_start(*menubar, Gtk::PACK_SHRINK, 0);
    Gtk::ScrolledWindow *scrolledwindow = Gtk::manage(new Gtk::ScrolledWindow);
    scrolledwindow->set_policy(Gtk::POLICY_AUTOMATIC,Gtk::POLICY_AUTOMATIC);
    //vbox->pack_start(*scrolledwindow);
    // vbox->add(*menubar);

    //     F I L E
    // Create a File menu and add to the menu bar
    Gtk::MenuItem *menuitem_file = Gtk::manage(new Gtk::MenuItem("_File", true));
    menubar->append(*menuitem_file);
    Gtk::Menu *filemenu = Gtk::manage(new Gtk::Menu());
    menuitem_file->set_submenu(*filemenu);

    //         N E W   S C H O O L
    // Append New to the File menu
    Gtk::MenuItem *menuitem_new = Gtk::manage(new Gtk::MenuItem("_New School", true));
    menuitem_new->signal_activate().connect([this] {this->on_new_school_click();});
    filemenu->append(*menuitem_new);

     //         O P E N
    // Append Open File to the File menu
    Gtk::MenuItem *menuitem_open = Gtk::manage(new Gtk::MenuItem("_Open", true));
    menuitem_open->signal_activate().connect([this] {this->on_open_click();});
    filemenu->append(*menuitem_open);

     //         S A V E  A S
    // Append Save as to the File menu
    Gtk::MenuItem *menuitem_saveas = Gtk::manage(new Gtk::MenuItem("_Save As", true));
    menuitem_saveas->signal_activate().connect([this] {this->on_save_as_click();});
    filemenu->append(*menuitem_saveas);

     //         S A V E
    // Append New to the File menu
    Gtk::MenuItem *menuitem_save = Gtk::manage(new Gtk::MenuItem("_Save", true));
    menuitem_save->signal_activate().connect([this] {this->on_save_click();});
    filemenu->append(*menuitem_save);

    //         Q U I T
    // Append Quit to the File menu
    Gtk::MenuItem *menuitem_quit = Gtk::manage(new Gtk::MenuItem("_Quit", true));
    menuitem_quit->signal_activate().connect([this] {this->on_quit_click();});
    filemenu->append(*menuitem_quit);


    //     I N S E R T
    // Create a Insert menu and add to the menu bar
    Gtk::MenuItem *menuitem_insert = Gtk::manage(new Gtk::MenuItem("_Insert", true));
    menubar->append(*menuitem_insert);
    Gtk::Menu *insertmenu = Gtk::manage(new Gtk::Menu());
    menuitem_insert->set_submenu(*insertmenu);

    Gtk::MenuItem *menuitem_newS = Gtk::manage(new Gtk::MenuItem("_New Student", true));
    menuitem_newS->signal_activate().connect([this] {this->on_new_student_click();});
    insertmenu->append(*menuitem_newS);

    Gtk::MenuItem *menuitem_newP = Gtk::manage(new Gtk::MenuItem("_New Parent", true));
    menuitem_newP->signal_activate().connect([this] {this->on_new_parent_click();});
    insertmenu->append(*menuitem_newP);

    Gtk::MenuItem *menuitem_newSection = Gtk::manage(new Gtk::MenuItem("_New Section", true));
    menuitem_newSection->signal_activate().connect([this] {this->on_new_section_click();});
    insertmenu->append(*menuitem_newSection);

    Gtk::MenuItem *menuitem_newCourse = Gtk::manage(new Gtk::MenuItem("_New Course", true));
    menuitem_newCourse->signal_activate().connect([this] {this->on_new_course_click();});
    insertmenu->append(*menuitem_newCourse);

    Gtk::MenuItem *menuitem_newT = Gtk::manage(new Gtk::MenuItem("_New Teacher", true));
    menuitem_newT->signal_activate().connect([this] {this->on_new_teacher_click();});
    insertmenu->append(*menuitem_newT);

    Gtk::MenuItem *menuitem_newTr = Gtk::manage(new Gtk::MenuItem("_New Transcript", true));
    menuitem_newTr->signal_activate().connect([this] {this->on_new_transcript_click();});
    insertmenu->append(*menuitem_newTr);

    Gtk::MenuItem *menuitem_newgrade = Gtk::manage(new Gtk::MenuItem("_Set Grade", true));
    menuitem_newgrade->signal_activate().connect([this] {this->on_set_grade_click();});
    insertmenu->append(*menuitem_newgrade);
    
    //     R E L A T E
    // Create a Relate menu and add to the menu bar
    Gtk::MenuItem *menuitem_relate = Gtk::manage(new Gtk::MenuItem("_Relate", true));
    menubar->append(*menuitem_relate);
    Gtk::Menu *relatemenu = Gtk::manage(new Gtk::Menu());
    menuitem_relate->set_submenu(*relatemenu);

    Gtk::MenuItem *menuitem_newSTP = Gtk::manage(new Gtk::MenuItem("_Student to Parent", true));
    menuitem_newSTP->signal_activate().connect([this] {this->on_student_parent_click();});
    relatemenu->append(*menuitem_newSTP);

    //     V I E W
    // Create a View menu and add to the menu bar
    Gtk::MenuItem *menuitem_view = Gtk::manage(new Gtk::MenuItem("_View", true));
    menubar->append(*menuitem_view);
    Gtk::Menu *viewmenu = Gtk::manage(new Gtk::Menu());
    menuitem_view->set_submenu(*viewmenu);

    Gtk::MenuItem *menuitem_viewS = Gtk::manage(new Gtk::MenuItem("_View Student", true));
    menuitem_viewS->signal_activate().connect([this] {this->on_view_student_click();});
    viewmenu->append(*menuitem_viewS);

    Gtk::MenuItem *menuitem_viewP = Gtk::manage(new Gtk::MenuItem("_View Parent", true));
    menuitem_viewP->signal_activate().connect([this] {this->on_view_parent_click();});
    viewmenu->append(*menuitem_viewP);

    Gtk::MenuItem *menuitem_viewSection = Gtk::manage(new Gtk::MenuItem("_View Section", true));
    menuitem_viewSection->signal_activate().connect([this] {this->on_view_section_click();});
    viewmenu->append(*menuitem_viewSection);

    Gtk::MenuItem *menuitem_viewCourse = Gtk::manage(new Gtk::MenuItem("_View Course", true));
    menuitem_viewCourse->signal_activate().connect([this] {this->on_view_course_click();});
    viewmenu->append(*menuitem_viewCourse);

    Gtk::MenuItem *menuitem_viewSP = Gtk::manage(new Gtk::MenuItem("_View Students and Parents", true));
    menuitem_viewSP->signal_activate().connect([this] {this->on_view_SP_click();});
    viewmenu->append(*menuitem_viewSP);

    Gtk::MenuItem *menuitem_viewTeacher = Gtk::manage(new Gtk::MenuItem("_View Teacher", true));
    menuitem_viewTeacher->signal_activate().connect([this] {this->on_view_teacher_click();});
    viewmenu->append(*menuitem_viewTeacher);

    Gtk::MenuItem *menuitem_viewTranscript = Gtk::manage(new Gtk::MenuItem("_View Transcript", true));
    menuitem_viewTranscript->signal_activate().connect([this] {this->on_view_transcript_click();});
    viewmenu->append(*menuitem_viewTranscript);

    //     H E L P
    // Create a Help menu and add to the menu bar
    Gtk::MenuItem *menuitem_help = Gtk::manage(new Gtk::MenuItem("_Help", true));
    menubar->append(*menuitem_help);
    Gtk::Menu *helpmenu = Gtk::manage(new Gtk::Menu());
    menuitem_help->set_submenu(*helpmenu);

    Gtk::MenuItem *menuitem_about = Gtk::manage(new Gtk::MenuItem("_About", true));
    menuitem_about->signal_activate().connect([this] {this->on_about_click();});
    helpmenu->append(*menuitem_about);

    // ///////////// //////////////////////////////////////////////////////////
    // T O O L B A R
    // Add a toolbar to the vertical box below the menu
    Gtk::Toolbar *toolbar = Gtk::manage(new Gtk::Toolbar);
    vbox->pack_start(*toolbar, Gtk::PACK_SHRINK, 0);
    // vbox->add(*toolbar);

    // //     N E W   S C H O O L
    // // Add a new school icon
    Gtk::ToolButton *new_school_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::NEW));
    new_school_button->set_tooltip_markup("Create a new school....");
    new_school_button->signal_clicked().connect([this] {this->on_new_school_click();});
    toolbar->append(*new_school_button);

    // //     O P E N F I L E
    // // Add an icon for openning one file
    Gtk::Image* open_image = Gtk::manage(new Gtk::Image{"icon_images/investment-1.1s-200px32.png"});
    open = Gtk::manage(new Gtk::ToolButton(*open_image));
    open->set_tooltip_markup("Open File");
    open->signal_clicked().connect([this] {this->on_open_click();});
    toolbar->append(*open);

    // //     S A V E A S
    // // Add an icon save as
    Gtk::Image* save_as_image = Gtk::manage(new Gtk::Image{"icon_images/piggy-bank32.png"});
    save_as = Gtk::manage(new Gtk::ToolButton(*save_as_image));
    save_as->set_tooltip_markup("Save As");
    save_as->signal_clicked().connect([this] {this->on_save_as_click();});
    toolbar->append(*save_as);

    // //     S A V E
    // // Add an icon for save
    Gtk::Image* save_image = Gtk::manage(new Gtk::Image{"icon_images/money-saving-dollar32.png"});
    save = Gtk::manage(new Gtk::ToolButton(*save_image));
    save->set_tooltip_markup("Save");
    save->signal_clicked().connect([this] {this->on_save_click();});
    toolbar->append(*save);

    // // S E P E R A T O R
    Gtk::SeparatorToolItem *sep = Gtk::manage(new Gtk::SeparatorToolItem());
    toolbar->append(*sep);

    // //     N E W  S T U D E N T
    // // Add icon to insert student
    Gtk::Image* student_image = Gtk::manage(new Gtk::Image{"icon_images/boy-girl32.png"});
    studenticon = Gtk::manage(new Gtk::ToolButton(*student_image));
    studenticon->set_tooltip_markup("New Student");
    studenticon->signal_clicked().connect([this] {this->on_new_student_click();});
    toolbar->append(*studenticon);

    // //     N E W  P A R E N T
    // // Add icon to insert student
    Gtk::Image* parent_image = Gtk::manage(new Gtk::Image{"icon_images/family32.png"});
    parenticon = Gtk::manage(new Gtk::ToolButton(*parent_image));
    parenticon->set_tooltip_markup("New Parent");
    parenticon->signal_clicked().connect([this] {this->on_new_parent_click();});
    toolbar->append(*parenticon);

    // //     R E L A T E  S T U D E N T A N D  P A R E N T
    // // Add icon to insert student
    Gtk::Image* relate_image = Gtk::manage(new Gtk::Image{"icon_images/online-community32.png"});
    relateicon = Gtk::manage(new Gtk::ToolButton(*relate_image));
    relateicon->set_tooltip_markup("Relate Student to Parent");
    relateicon->signal_clicked().connect([this] {this->on_student_parent_click();});
    toolbar->append(*relateicon);

       // //     N E W  T E A C H E R 
    // // Add icon to insert student
    Gtk::Image* teacher_image = Gtk::manage(new Gtk::Image{"icon_images/conference-education32.png"});
    teachericon = Gtk::manage(new Gtk::ToolButton(*teacher_image));
    teachericon->set_tooltip_markup("New Teacher");
    teachericon->signal_clicked().connect([this] {this->on_new_teacher_click();});
    toolbar->append(*teachericon);

    // // S E P E R A T O R
    Gtk::SeparatorToolItem *nextsep = Gtk::manage(new Gtk::SeparatorToolItem());
    toolbar->append(*nextsep);

    // //     N E W  S E C T I O N
    // //     N E W  C O U R S E
    Gtk::Image* course_image = Gtk::manage(new Gtk::Image{"icon_images/online-course32.png"});
    courseicon = Gtk::manage(new Gtk::ToolButton(*course_image));
    courseicon->set_tooltip_markup("New Course");
    courseicon->signal_clicked().connect([this] {this->on_new_course_click();});
    toolbar->append(*courseicon);

    Gtk::Image* section_image = Gtk::manage(new Gtk::Image{"icon_images/presentation-learning32.png"});
    sectionicon = Gtk::manage(new Gtk::ToolButton(*section_image));
    sectionicon->set_tooltip_markup("New Section");
    sectionicon->signal_clicked().connect([this] {this->on_new_section_click();});
    toolbar->append(*sectionicon);

    // //     N E W  T R A N S C R I P T
    Gtk::Image* transcript_image = Gtk::manage(new Gtk::Image{"icon_images/contract-agreement32r.png"});
    transcripticon = Gtk::manage(new Gtk::ToolButton(*transcript_image));
    transcripticon->set_tooltip_markup("New Transcript");
    transcripticon->signal_clicked().connect([this] {this->on_new_transcript_click();});
    toolbar->append(*transcripticon);

    // //     N E W  C O U R S E
    Gtk::Image* grade_image = Gtk::manage(new Gtk::Image{"icon_images/result-fail32r.png"});
    gradeicon = Gtk::manage(new Gtk::ToolButton(*grade_image));
    gradeicon->set_tooltip_markup("Set Grade");
    gradeicon->signal_clicked().connect([this] {this->on_set_grade_click();});
    toolbar->append(*gradeicon);


    // /////////////////////////// ////////////////////////////////////////////
    // F U L L I N F O   D I S P L A Y
    display = Gtk::manage(new Gtk::Label());
    display->set_hexpand(true);
    display->set_vexpand(true);
    vbox->add(*display);
    
    // S T A T U S   B A R   D I S P L A Y ////////////////////////////////////
    // Provide a status bar for game messages
    // msg = Gtk::manage(new Gtk::Label());
    // msg->set_hexpand(true);
    // vbox->pack_start(*msg, Gtk::PACK_SHRINK, 0);
    // vbox->add(*msg);

    // Make the box and everything in it visible
    vbox->show_all();

    // Start a new school
    on_new_school_click();
}


Mainwin::~Mainwin() {

    for(Student* s : students) delete s;
    for(Parent* p : parents) delete p;
    for(Course* c : courses) delete c;
    for(Section* se : sections) delete se;
    for(Teacher* t : teachers) delete t;
    for(Transcript* tr : transcripts) delete tr;

}

// /////////////////
// C A L L B A C K S
// /////////////////

void Mainwin::on_new_school_click(){
    for(Student* s : students) delete s;
    for(Parent* p : parents) delete p;
    for(Teacher* t : teachers) delete t;
    for(Transcript* tr : transcripts) delete tr;
    for(Course* c : courses) delete c;
    for(Section* se : sections) delete se;
    students.clear();
    parents.clear();
    courses.clear();
    sections.clear();
    teachers.clear();
    transcripts.clear();
    show_data();
} 

void Mainwin::on_new_student_click(){

    try{
        Gtk::Dialog dialogs{"Student", *this};
        Gtk::HBox qbox;
        Gtk::HBox vecbox;
        Gtk::HBox spinbox;
        Gtk::Label tn{"Name:"};
        Gtk::Entry te_n;
        qbox.add(tn);
        qbox.add(te_n);
        Gtk::Label te{"Email:"};
        Gtk::Entry te_e;
        vecbox.add(te);
        vecbox.add(te_e);
        Gtk::Label lq{"Year"};
        spinbox.add(lq);
        Gtk::SpinButton sb;
        sb.set_range(1, 12);
        sb.set_increments(1.0, 1.0);
        spinbox.add(sb);
        dialogs.get_content_area()->add(qbox);
        dialogs.get_content_area()->add(vecbox);
        dialogs.get_content_area()->add(spinbox);
        dialogs.get_vbox()->show_all();
        dialogs.add_button("Enter", 1);
        dialogs.add_button("Cancel", 0);
        int result = dialogs.run();
        if (result ==1){
            std::string name = te_n.get_text();
            std::string email = te_e.get_text();
            int grade = sb.get_value();    
            students.push_back(new Student{name, email, grade});
        }else return;
    
    }catch(std::exception& e){
        
        Gtk::MessageDialog{*this, e.what()}.run();
    
    } 
    show_data();     
    
}   

void Mainwin::on_new_parent_click(){
    
    try{            
        Gtk::Dialog dialogs{"Parent", *this};
        Gtk::HBox qbox;
        Gtk::HBox vecbox;
        Gtk::Label tn{"Name:"};
        Gtk::Entry te_n;
        qbox.add(tn);
        qbox.add(te_n);
        Gtk::Label te{"Email:"};
        Gtk::Entry te_e;
        vecbox.add(te);
        vecbox.add(te_e);
        dialogs.get_content_area()->add(qbox);
        dialogs.get_content_area()->add(vecbox);
        dialogs.get_vbox()->show_all();
        dialogs.add_button("Enter", 1);
        dialogs.add_button("Cancel", 0);
        int result = dialogs.run();
        if (result ==1){
            
            std::string name = te_n.get_text();
            std::string email = te_e.get_text();
            parents.push_back(new Parent{name, email});

        }else return;
        

    }catch(std::exception& e){
        
        Gtk::MessageDialog{*this, e.what()}.run();
    
    } 
    show_data();
}

// Get Current Year
int Mainwin::current_year(){
    
    std::time_t t = std::time(nullptr);
    std::tm *const time_info = std::localtime(&t);
    return 1900 + time_info->tm_year;

}

void Mainwin::on_new_course_click(){
    
    try{
        Gtk::Dialog dialogs{"Course", *this};
        std::ostringstream oss;
        Gtk::ComboBoxText cbt;
        for(auto s : subjects) {
            oss.str(""); 
            oss << s;
            cbt.append(oss.str());
        }
        Gtk::VBox lbox;
        Gtk::Label ll{"Select Subject"};
        lbox.add(ll);
        //scrolledwindow->container_add(dialogs,cbt);
        //dialogs.pack_start(scrolledwindow);
        //dialogs.get_vbox()->pack_start(*scrolledwindow); //work on scroll
        dialogs.get_content_area()->add(lbox);
        dialogs.get_vbox()->pack_start(cbt);
        Gtk::HBox qbox;
        Gtk::Label lq{"Year"};
        qbox.add(lq);
        Gtk::SpinButton sb;
        sb.set_range(1, 12);
        sb.set_increments(1.0, 1.0);
        qbox.add(sb);
        dialogs.get_content_area()->add(qbox);
        dialogs.get_vbox()->show_all();
        dialogs.add_button("Enter", 1);
        dialogs.add_button("Cancel", 0);
        int result = dialogs.run();
        if (result == 1){
            Subject subject  = subjects.at(cbt.get_active_row_number());
            int grade = sb.get_value();
            courses.push_back(new Course{subject, grade});
        
        }
        else return;      

    }
    catch(std::exception& e){
        Gtk::MessageDialog{*this, e.what()}.run();
    }
    
    on_view_course_click();
    
}

void Mainwin::on_new_section_click(){
     
    if (teachers.empty() and !courses.empty()) {
        Gtk::MessageDialog dialog{*this, "Add Teacher to Add Section"};
        dialog.set_modal(true);
        dialog.run();
    } 
    else if (courses.empty() and !teachers.empty()) {
        Gtk::MessageDialog dialog{*this, "Add Course to Add Section"};
        dialog.set_modal(true);
        dialog.run();
    } 
    else if (courses.empty() and teachers.empty()) {
        Gtk::MessageDialog dialog{*this, "Add Course and Teacher to Add Section"};
        dialog.set_modal(true);
        dialog.run();
    } 
    else {
        try {
            Gtk::Dialog dialogs{"Teacher to Section", *this};
            ComboBoxContainer<std::vector<Course *>> cbt_courses(courses);
            ComboBoxContainer<std::vector<Teacher *>> cbt_teachers(teachers);
            Gtk::VBox lbox, tbox;
            Gtk::Label ll{"Select Course"};
            lbox.add(ll);
            Gtk::Label tl{"Select Teacher"};
            tbox.add(tl);
            dialogs.get_content_area()->add(lbox);
            dialogs.get_vbox()->pack_start(cbt_courses);
            dialogs.get_content_area()->add(tbox);
            dialogs.get_vbox()->pack_start(cbt_teachers);
            Gtk::HBox qbox;
            Gtk::Label lq{"Year"};
            qbox.add(lq);
            Gtk::SpinButton sb;
            sb.set_range(curr_year, 2050); 
            sb.set_increments(1.0, 1.0);
            qbox.add(sb);
            dialogs.get_content_area()->add(qbox);
            dialogs.get_vbox()->show_all();
            dialogs.add_button("Cancel", -1);
            dialogs.add_button("Fall", 0);
            dialogs.add_button("Spring", 1);
            dialogs.add_button("Summer", 2);
            int year;
            int result = dialogs.run();
            if (result == 0 || result == 1 || result == 2) {
                year = static_cast<int>(sb.get_value());
                Course &courseAt =
                    *courses.at(cbt_courses.get_active_row_number());
                Semester semester = semesters.at(result);
                year = static_cast<int>(sb.get_value());
                Teacher &teacherAt =
                    *teachers.at(cbt_teachers.get_active_row_number());
                sections.push_back(
                    new Section{courseAt, teacherAt, semester, year});

            } else
                return;
        } catch (std::exception &e) {
            Gtk::MessageDialog{*this, e.what()}.run();
        }

        on_view_section_click(); 
    }
}

void Mainwin::on_new_teacher_click(){
    try{  
        Gtk::Dialog dialogs{"Teacher", *this};
        Gtk::HBox qbox;
        Gtk::HBox vecbox;
        Gtk::Label tn{"Name:"};
        Gtk::Entry te_n;
        qbox.add(tn);
        qbox.add(te_n);
        Gtk::Label te{"Email:"};
        Gtk::Entry te_e;
        vecbox.add(te);
        vecbox.add(te_e);
        dialogs.get_content_area()->add(qbox);
        dialogs.get_content_area()->add(vecbox);
        dialogs.get_vbox()->show_all();
        dialogs.add_button("Enter", 1);
        dialogs.add_button("Cancel", 0);
        int result = dialogs.run();
        if (result ==1){
            
        std::string name = te_n.get_text();
        std::string email = te_e.get_text();
        teachers.push_back(new Teacher{name, email});  
        
        }else return;
          
             
    }catch(std::exception& e){
        
        Gtk::MessageDialog{*this, e.what()}.run();
    
    } 
    on_view_teacher_click();
}
void  Mainwin::on_new_transcript_click(){
    if (students.empty() and !sections.empty()) {
        Gtk::MessageDialog dialog{*this, "Add Student to Add Section"};
        dialog.set_modal(true);
        dialog.run();
    } else if (sections.empty() and !students.empty()) {
        Gtk::MessageDialog dialog{*this, "Add Section to Relate"};
        dialog.set_modal(true);
        dialog.run();
    } else if (students.empty() and sections.empty()) {
        Gtk::MessageDialog dialog{*this, "Add Section and Student"};
        dialog.set_modal(true);
        dialog.run();
    } else {
        try {  
        
        Gtk::Dialog dialogs{"Student to Section", *this};
        ComboBoxContainer<std::vector<Section*>> cbt_sections(sections);
        ComboBoxContainer<std::vector<Student*>> cbt_students(students);
        Gtk::VBox lbox, tbox;
        Gtk::Label ll{"Select Section"};
        lbox.add(ll);
        Gtk::Label tl{"Select Student"};
        tbox.add(tl);
        dialogs.get_content_area()->add(lbox);
        dialogs.get_vbox()->pack_start(cbt_sections);
        dialogs.get_content_area()->add(tbox);
        dialogs.get_vbox()->pack_start(cbt_students);
        dialogs.get_vbox()->show_all();
        dialogs.add_button("Enter", 1);
        dialogs.add_button("Cancel", 0);
        int result = dialogs.run();
        if (result ==1){
    
            Section& sectionAt = *sections.at(cbt_sections.get_active_row_number());
            Student& studentAt = *students.at(cbt_students.get_active_row_number());
            transcripts.push_back(new Transcript{studentAt,sectionAt}); 
            
        }else return;
    
        }catch(std::exception& e){
            
            Gtk::MessageDialog{*this, e.what()}.run();
        
        }
        on_view_transcript_click();
    }
}

void  Mainwin::on_set_grade_click(){
    
    if(transcripts.empty()){
        Gtk::MessageDialog dialog{*this, "Add Transcript of Student"};
        dialog.set_modal(true);
        dialog.run();
    }
    else{
        try{
            Gtk::Dialog dialog{"Set Grade", *this};
            Gtk::VBox sbox;
            Gtk::Label sl{"Select Transcript"};
            sbox.add(sl);
            ComboBoxContainer<std::vector<Transcript*>> cbt_transcripts(transcripts);
            dialog.get_content_area()->add(sbox);
            dialog.get_vbox()->pack_start(cbt_transcripts);    
            dialog.add_button("Cancel", -1);
            std::ostringstream oss;
            for(int i = 0; i < grades_vector.size() ; i++) {
                oss.str(""); 
                oss << grades_vector.at(i);
                dialog.add_button(oss.str(), i);
            }
            dialog.get_vbox()->show_all();
            int result = dialog.run();
            if(result >= 0 && result <= 6){
                Grade gradeAt = grades_vector.at(result);
                transcripts.at(cbt_transcripts.get_active_row_number())->assign_grade(gradeAt);
            }
            else return;

        }catch(std::exception& e){
            
            Gtk::MessageDialog{*this, e.what()}.run();
        
        } 
        on_view_transcript_click();
    }
}

void Mainwin::on_student_parent_click(){

    if (students.empty() and !parents.empty()) {
        Gtk::MessageDialog dialog{*this, "Add Student to Relate"};
        dialog.set_modal(true);
        dialog.run();
    } 
    else if (parents.empty() and !students.empty()) {
        Gtk::MessageDialog dialog{*this, "Add Parent to Relate"};
        dialog.set_modal(true);
        dialog.run();
    } 
    else if (parents.empty() and students.empty()) {
        Gtk::MessageDialog dialog{*this, "Add Parent and Student to Relate"};
        dialog.set_modal(true);
        dialog.run();
    } 
    else {
        try{
            Gtk::Dialog dialog{"Relate Student and Parent", *this};
            Gtk::VBox sbox,pbox;
            Gtk::Label sl{"Select Student"};
            Gtk::Label pl{"Select Parent"};
            sbox.add(sl);
            pbox.add(pl);
            ComboBoxContainer<std::vector<Student*>> cbt_students(students);
            ComboBoxContainer<std::vector<Parent*>> cbt_parents(parents);
            dialog.get_content_area()->add(sbox);
            dialog.get_vbox()->pack_start(cbt_students);
            dialog.get_content_area()->add(pbox);
            dialog.get_vbox()->pack_start(cbt_parents);
            dialog.add_button("Relate", 1);    
            dialog.add_button("Cancel", 0);
            dialog.get_vbox()->show_all();
            int result = dialog.run();
            if(result == 1){
                students.at(cbt_students.get_active_row_number())->add_parent(*parents.at(cbt_parents.get_active_row_number()));
                parents.at(cbt_parents.get_active_row_number())->add_student(*students.at(cbt_students.get_active_row_number()));
            }
            else return;

        }
        catch(std::exception& e){
            Gtk::MessageDialog{*this, e.what()}.run();
        }
        
        show_data();
    }
}             
void Mainwin::on_view_student_click(){
    Glib::ustring v = "";
    v += "<span size='13000' weight='bold'>Students</span>\n\n";
    for(auto s : students)  v.append(s->full_info() + "\n");
    display->set_markup(v);
}              

void Mainwin::on_view_parent_click(){
    Glib::ustring v = "";
    v += "<span size='13000' weight='bold'>Parents</span>\n\n";
    for(auto  p : parents)  v.append(p->full_info() + "\n");  
    display->set_markup(v);
}

void Mainwin::on_view_section_click(){
    Glib::ustring v = "";
    v += "<span size='13000' weight='bold'>Section</span>\n\n";
    for(auto  s : sections)  v.append(s->to_string() + "\n");  
    display->set_markup(v);
}              

void Mainwin::on_view_course_click(){
    Glib::ustring v = "";
    v += "<span size='13000' weight='bold'>Course</span>\n\n";
    for(auto  c : courses)  v.append(c->to_string() + "\n");  
    display->set_markup(v);
}

void Mainwin::on_view_transcript_click(){
    std::ostringstream oss;
    oss << "<span size='13000' weight='bold'>Transcripts</span>\n\n";
    for(int i=0; i<transcripts.size(); ++i) 
    oss << *transcripts.at(i) << '\n';
    display->set_markup(oss.str());
}

void Mainwin::on_view_teacher_click(){
    Glib::ustring v = "";
    v += "<span size='13000' weight='bold'>Teacher</span>\n\n";
    for(auto  t : teachers)  v.append(t->full_info() + "\n");  
    display->set_markup(v);
}

void Mainwin::on_view_SP_click(){
    show_data();
}

void Mainwin::show_data(){
    
    Glib::ustring v = "";
    v += "<span size='13000' weight='bold'>Students</span>\n\n";
    for(auto s : students)  v.append(s->full_info() + "\n");
    v += "<span size='13000' weight='bold'>Parents</span>\n\n";
    for(auto  p : parents)  v.append(p->full_info() + "\n");  
    display->set_markup(v);

}        

void Mainwin::on_quit_click() {
   
    close();

}

void Mainwin::on_about_click(){

    Gtk::AboutDialog dialog;
    dialog.set_transient_for(*this); 
    dialog.set_program_name("SMART");
    auto logo = Gdk::Pixbuf::create_from_file("icon_images/pexels-louis-3143809smaller.jpg");
    dialog.set_logo(logo);
    dialog.set_version("Version 1.3.0");
    dialog.set_copyright("Copyright " + std::to_string(curr_year));
    dialog.set_license_type(Gtk::License::LICENSE_MIT_X11);
    std::vector< Glib::ustring > authors = {"Gerald Kimeu"};
    dialog.set_authors(authors);
    std::vector< Glib::ustring > artists = {
        "School Bus Photo by Louis, licensed free to use any personal and commercial projects without any attribution or credit https://www.pexels.com/photo/shallow-focus-photo-of-yellow-bus-3143809", "Piggy Bank Icon,licensed free to use any personal and commercial projects without any attribution or credit https://uxwing.com/piggy-bank-icon/", 
        "Money Saving Dollar Icon,licensed free to use any personal and commercial projects without any attribution or credit https://uxwing.com/money-saving-dollar-icon/", 
        "Loading Pig, licensed for personal and commercial purposes with attribution https://loading.io/icon/set/pjepdy-piggy-bank ",
        "Student Icon,licensed free to use any personal and commercial projects without any attribution or credit https://uxwing.com/boy-girl-icon/",
        "Family Icon,licensed free to use any personal and commercial projects without any attribution or credit https://uxwing.com/family-icon/",
        "Relate Icon,licensed free to use any personal and commercial projects without any attribution or credit https://uxwing.com/online-community-icon/",
        "Course Icon,licensed free to use any personal and commercial projects without any attribution or credit https://uxwing.com/online-course-icon/",
        "Section Icon,licensed free to use any personal and commercial projects without any attribution or credit https://uxwing.com/presentation-learning-icon/",
        "Teacher Icon,licensed free to use any personal and commercial projects without any attribution or credit https://uxwing.com/conference-education-icon/",
        "Grade Icon,licensed free to use any personal and commercial projects without any attribution or credit https://uxwing.com/result-fail-icon/",
        "Transcript Icon,licensed free to use any personal and commercial projects without any attribution or credit https://uxwing.com/contract-agreement-icon/"

    };
    dialog.set_artists(artists);
    dialog.run();


}

void Mainwin::on_open_click() {
    Gtk::FileChooserDialog dialog("Please choose a file",
          Gtk::FileChooserAction::FILE_CHOOSER_ACTION_OPEN);
    dialog.set_transient_for(*this);

    auto filter_smart = Gtk::FileFilter::create();
    filter_smart->set_name("SMART files");
    filter_smart->add_pattern("*.smart");
    dialog.add_filter(filter_smart);
 
    auto filter_any = Gtk::FileFilter::create();
    filter_any->set_name("Any files");
    filter_any->add_pattern("*");
    dialog.add_filter(filter_any);

    dialog.set_filename(filename);

    dialog.add_button("_Open", 1);
    dialog.add_button("_Cancel", 0);
    

    int result = dialog.run();

    if (result == 1) {
        try {
            filename = dialog.get_filename();
            std::ifstream ifs{filename};
            on_new_school_click();
            show_data();
            int student_size, parent_size, section_size, course_size, teacher_size, transcript_size;
            ifs >> student_size;
            while(student_size--) students.push_back(new Student{ifs});           
            ifs >> parent_size;
            while(parent_size--) parents.push_back(new Parent{ifs});
            ifs >> course_size;
            while(course_size--) courses.push_back(new Course{ifs});
            ifs >> section_size; 
            while(section_size--) sections.push_back(new Section{ifs});
            ifs >> teacher_size; 
            while(teacher_size--) teachers.push_back(new Teacher{ifs});
            ifs >> transcript_size;
            while(transcript_size--) transcripts.push_back(new Transcript{ifs});     
            if(!ifs) throw  std::runtime_error{"File contents bad"};
            show_data(); 
        } catch (std::exception& e) {
            Gtk::MessageDialog{*this, "Unable to open File"}.run();
        }
    }
    show_data();
}

void Mainwin::on_save_click(){

    try {           
        std::ofstream ofs{filename};
        ofs << students.size() << std::endl;
        for(auto  s : students) s->save(ofs);
        ofs << parents.size() << std::endl;
        for(auto  p : parents) p->save(ofs);
        ofs << courses.size() << std::endl;
        for(auto  cou : courses) cou->save(ofs);
        ofs << sections.size() << std::endl;
        for(auto  sec : sections) sec->save(ofs);
        ofs << teachers.size() << std::endl;
        for(auto  tea : teachers) tea->save(ofs);
        ofs << transcripts.size() << std::endl;
        for(auto  tra : transcripts) tra->save(ofs);
        if(!ofs) throw std::runtime_error{"File contents bad"};
        show_data();
    }catch (std::exception& e) {
        Gtk::MessageDialog{*this, "Unable to Save File"}.run();
    }    

}

void Mainwin::on_save_as_click(){
    
    Gtk::FileChooserDialog dialog("Please choose a file",
    Gtk::FileChooserAction::FILE_CHOOSER_ACTION_SAVE);
    dialog.set_transient_for(*this);

    auto filter_smart = Gtk::FileFilter::create();
    filter_smart->set_name("SMART files");
    filter_smart->add_pattern("*.smart");
    dialog.add_filter(filter_smart);
 
    auto filter_any = Gtk::FileFilter::create();
    filter_any->set_name("Any files");
    filter_any->add_pattern("*");
    dialog.add_filter(filter_any);

    dialog.set_filename(filename);

    dialog.add_button("_Save", 1);
    dialog.add_button("_Cancel", 0);
    
    int result = dialog.run();

    filename = dialog.get_filename();

    if (result == 1) {
        on_save_click();
        
    }
    show_data();

}

