#include <login.h>
#include <ansi.h> 
//function definition
int start_test(); 
inherit NPC; 
mapping *question_list=({
        ([      "question": "Q1: Are you a man or woman?(Pick one from the following)",
                "answer": ({
                                ({"A: man",10,}),
                                ({"B: woman",10}),      
                                ({"C: Both",10,}),
                                ({"D: Neither",10,})
                }),
        ]),
        ([      "question": "Q2: Are you a man or woman?(Pick one from the following)",
                "answer": ({
                                ({"A: man",20,}),
                                ({"B: woman",20}),      
                                ({"C: Both",20,}),
                                ({"D: Neither",20,})
                }),
        ]),
        ([      "question": "Q3: Are you a man or woman?(Pick one from the following)",
                "answer": ({
                                ({"A: man",30,}),
                                ({"B: woman",30}),      
                                ({"C: Both",30,}),
                                ({"D: Neither",30,})
                }),
        ]),
        ([      "question": "Q4: Are you a man or woman?(Pick one from the following)",
                "answer": ({
                                ({"A: man",40,}),
                                ({"B: woman",40}),      
                                ({"C: Both",40,}),
                                ({"D: Neither",40,})
                }),
        ]),
}); 
string get_question(int i)
{
        int j;
        string temp = question_list[i]["question"] + "\n";
        for (j=0;j<4;j++)
        {
                temp = temp + question_list[i]["answer"][j][0] + "\n";
        }
        return temp;
}  
void create()
{
        set_name("������", ({ "news man"}) );
        set("title",YEL "������֪"NOR);
        set("long", "���ƺ�ʲô��֪������˭Ҳ��֪��������֪��ʲô��\n");
        set("gender", "����");
        set("age", 70);
        set("no_fight",1);
        set("combat_exp", 9000);
        set("score", 0);
        set ("no_arrest",1);
        set("in_test",0);
        setup();
} 
