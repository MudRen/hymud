#include <ansi.h>
#include <command.h>

inherit NPC; 
void create()
{ 
        set_name("林二",({"lin er","lin"}));
        set("title",RED"戴红缨帽的官差"NOR);
        set("long", "
常笑座下十三官差中仵作行的高手，不管死因是什么，只要是世间有过的，他都能
查出。只要凶手是人，不管用什么武器，什么方法，都瞒不过他。。\n");
        
        set("age",37);
        set("combat_exp", 6000000);
        set("attitude", "friendly");     
        set("resistance/gin",30);
        set("resistance/kee",30);
        set("resistance/sen",30); 
        set("inquiry", ([
                 "铁恨": "铁捕头和常老爷齐名，是天下四大名捕之一。",
                 "tie hen": "铁捕头和常老爷齐名，是天下四大名捕之一。",
                 "tiehen": "铁捕头和常老爷齐名，是天下四大名捕之一。",
        ]));
        
//      setting up special NPC function: healer, defense, zombie-killer
//      defense_type: 1. xiaohun-sword; 2.xiaohun-whip;3 yue-strike;4 lingxi-zhi;
        
//      set("defense_type",random(2)+1);        
//      set("zombie-killer",1);
//      set("officer-killer",1);
//      set("dungeon_npc","check");
        
        set("nb_chat_chance", 100);
        set("nb_chat_msg_combat", ([
        
        ]) );           
        


        
        setup();
        carry_object(__DIR__"obj/o_cloth3")->wear();
        carry_object(__DIR__"obj/redhat")->wear();
} 
int accept_object(object who, object ob)
{
        if( ob->name()=="谭天龙的尸体" || ob->name()=="谭天虎的尸体"
                || ob->name()=="谭天豹的尸体") {
                command("hmm");
                who->set("parrot/尸体的秘密",1);                                 
                call_out("event1",1,who,0);
                return 1;
        }        
        return 0;
}  
string *event1_msg=     ({
        
        CYN"\n  林二说：“此人死于暗器。“\n",
        
        CYN"  林二把尸体放在桌上，迅速地开始解剖。刀刮下的惨白的皮肉外翻，血泥浆一
样骨都骨都涌出。肠脏都已取出，堆在一旁。\n"NOR,
        
        CYN"  暗器竟真的就在心脏之内！寸许长，头发般粗细的钢针正嵌在心瓣之上。整个
心脏都变成黑色，仿如在墨汁中捞上来。\n"NOR,
        
        CYN"  林二用镊子夹起针端详了一阵说：“针是七星堂精制，毒是最毒的牵机毒，这
种毒针，其实就是"NOR+HIM"七星绝命针"NOR+CYN"。七星绝命针原是七星堂莫氏七兄弟的独门暗器，
莫氏七兄弟当年因为开罪了天魔女，西河口一战之后，七星就只剩一星，亦即是
莫冲。“\n"NOR,
        });  
void event1(object me, int count)
{
        if (environment(me)!=environment(this_object()) 
           || this_object()->is_fighting())        return;
        message_vision(event1_msg[count]+"\n",me);
        if(++count==sizeof(event1_msg))
        {
                message_vision(CYN"  “七星堂也就在那一战之后没落，莫冲变成了陕北的一个独行巨盗，却已在四
年前为"NOR+WHT"铁恨"+CYN"所擒，病死在大牢。”\n\n"NOR,this_object(),me);
                return;
        }
        else call_out("event1",2,me,count);
        return ;
} 
/*
void init() {
        
        object ob;
        ::init();
        add_action("do_answer","answer");
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}  
void greeting(object ob) {
        
        if( !ob || environment(ob) != environment() || ob->is_fighting()) return;
        call_out("ask_question_1",1,ob); 
}
*/   
