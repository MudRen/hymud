#include <ansi.h>
#include <command.h> 
inherit NPC; 
void create()
{ 
        set_name("���´�",({"blue cloth man","man"}));
        set("title",WHT"�ߺ�ɽׯ"NOR);
        set("long", "�ߺ������Ӹ���Ƹ���ĸ��֣������£��ֳֵָ���\n");
        set("age",40);
        set("combat_exp", 4500000);
                
        set("max_atman", 600);
        set("atman", 600);
        set("max_mana", 600);
        set("mana", 600);
        set("max_force",1500);
        set("force",1500);
        set("force_factor",100);
        set("group","qihai");
        
        set("str",40);
        set("cor", 40);
        set("cps", 40);
        set("agi",40);
        set("fle",40);
        
        set("resistance/gin",10);
        set("resistance/kee",10);
        set("resistance/sen",10);
        
                
//      setting up special NPC function: healer, defense, zombie-killer
//      defense_type: 1. xiaohun-sword; 2.xiaohun-whip;3 yue-strike;4 lingxi-zhi;
        
//      set("defense_type",random(2)+1);        
//      set("zombie-killer",1);
//      set("officer-killer",1);
//      set("dungeon_npc","check");
        
        set("nb_chat_chance", 100);
           set("nb_chat_msg_combat", ([
                1: name()+"�ȵ������ٲ������������������£�������Ҳ�߲����ˣ���\n", 
        ]) );  
        
        set("chat_chance", 1);
        set("chat_msg", ({
                "���´󺺰����������õ����Ŵ����ϵ�һ��ľͷ��\n",
                "���´�˵���������������ֳ��ֺȣ�����ȴ����ͷ�ɺ��ţ���ˬ����\n",
                "���´󺺲��������������Ķ�����������Ц��������\n",
                "���´������������ֹ��ţ�����ô��û���࣬�������ﶼ�����������ˡ���\n",
        }) ); 
        

        setup();
        carry_object(__DIR__"obj/bluecloth")->wear();
}  
int accept_object(object who, object ob)
{
        if (ob->query("food_supply")) {
        if (ob->query("food_remaining")) {
                if (ob->query("value")>=2000) {
                        message_vision(CYN"
$N�������촽˵����ͦ���ɵģ��������ȥתת�ɣ���Ҫ����������������û�ù��ӳԣ���\n"NOR,this_object());
                        who->set_temp("taiping/boat_enter",1);
                        return 1;
                } else 
                        message_vision(CYN"
$N��м�ؿ���"+ob->name()+"һ��˵����ʲô���߰�������������\n"NOR,this_object());
        } else 
                message_vision(CYN"$N��ŭ������С����ڿ��ү����\n"NOR,this_object());   
        }
        
        return 0;
}       
