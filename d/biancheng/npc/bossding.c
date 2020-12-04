#include <ansi.h>
//inherit "/d/taiping/npc/smart_npc"; 
inherit NPC;
int kill_him(); 
void create()
{
        set_name("������",({"ding laosi","ding","laosi"}));
        set("title","С����");
        set("long","����������ϵ���ǿ���Χȹ��\n");
        set("gender","����");
        set("age",32);
                
        set("int",22);
        set("cor",30);
        set("cps",20);
        set("str",40);
        
        set_skill("unarmed",200);
        set_skill("dodge",150);
        set_skill("parry",160);
        set_skill("force",180);
        set_skill("move",200); 
        
        set("neili",1500);
        set("max_neili",1500);
        set("force_factor",120);
        set("max_atman",500);
        set("atman",500);
        set("max_mana",500);
        set("mana",500);
        set("combat_exp",4000000);  
        set("attitude", "friendly");
        
        set("inquiry", ([
                "ǿ��" : "������ǿ��������Ҳ��ǿ���������ӿ���ô����ȥѽ��\n",
                "�����ǿ��" : "������������կ����Щɽ��ô��\n",
                "���ڵ�ǿ��" : "����˵������˵ѽ����\n",
                "�����嶾"   :          (: kill_him :),
                "������"     :          (: kill_him :),
        ]));
        
        
        set("death_msg",CYN"\n$N�ں޵�˵�����ҵĽ��������ǡ������εá���̫������������\n"NOR);          
                  
        
/*        CHAR_D->setup_char(this_object());
        auto_npc_setup("wang",200,160,0,"/obj/weapon/","fighter_w","lianxin-blade",2);
 */       
        setup();
        carry_object("/clone/misc/cloth")->wear();    
    
}  
int kill_him()
{
        object me, another;
        object ob;
        
        ob=this_object();
        me = this_player();
        if (this_object()->is_fighting()) {
                tell_object(me,"����������û�ջش��㡣\n");
                return 1;
                }
        message_vision(CYN"$N���Ϻ�Ȼ¶�����䵭�����ص�΢Ц������Ц�ݱ����ó������ϵġ�\n"NOR,this_object());
        message_vision(CYN"$N����Ц�ŵ�������Ȼ��֪���ˣ��Ͳ��������ٻ��ų�ȥ��\n",this_object());
        another = new(__DIR__"qingzhu");
        another->move(environment(this_object()));
        destruct(ob);
        return 1;
}
