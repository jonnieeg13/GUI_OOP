#ifndef __MAINWIN_H
#define __MAINWIN_H

#include <gtkmm.h>
#include <vector>
#include <fstream>
#include "student.h"
#include "parent.h"
#include "entrydialog.h"
#include "section.h"
#include "comboboxcontainer.h"
#include "teacher.h"
#include "transcript.h"

const int MAX_STUDENTS = 100;
const int MAX_PARENTS = 400;
const int MAX_COURSES = 50;
const int MAX_SECTIONS = 50;
const int MAX_TRANSCRIPTS = 100;
const int MAX_TEACHERS = 100;

class Mainwin : public Gtk::Window {
    
    public:
        Mainwin();
        virtual ~Mainwin();
    
    protected:
        void on_new_school_click();         
        void on_new_student_click();   
        void on_new_parent_click();            
        void on_student_parent_click();
        void on_new_course_click();   
        void on_new_section_click();
        void on_new_teacher_click();
        void on_new_transcript_click();   
        void on_set_grade_click();
        void on_view_student_click();              
        void on_view_parent_click();
        void on_view_section_click();              
        void on_view_course_click();
        void on_view_SP_click();
        void on_view_teacher_click();              
        void on_view_transcript_click();
        void on_quit_click();
        void on_about_click();
        void on_open_click();
        void on_save_as_click();
        void on_save_click();

    private:
        void show_data();
        std::vector<Student*> students;                   
        std::vector<Parent*> parents;
        std::vector<Course*> courses;                   
        std::vector<Section*> sections;
        std::vector<Teacher*> teachers;
        std::vector<Transcript*> transcripts;                             
        Gtk::Label *display; 
        std::string filename;                    
        int studentindex;
        int parentindex;
        std::string prints(const std::vector<Student>& students);
        std::string printp(const std::vector<Parent>& parents);
        std::string printSub();
        std::string printSect(); 
        Gtk::ToolButton *open;
        Gtk::ToolButton *save;
        Gtk::ToolButton *save_as;
        Gtk::ToolButton *studenticon;
        Gtk::ToolButton *parenticon;
        Gtk::ToolButton *relateicon;
        Gtk::ToolButton *sectionicon;
        Gtk::ToolButton *courseicon;
        Gtk::ToolButton *teachericon;
        Gtk::ToolButton *transcripticon;
        Gtk::ToolButton *gradeicon;
        Gtk::ScrolledWindow *scrolledwindow;

};
#endif 

