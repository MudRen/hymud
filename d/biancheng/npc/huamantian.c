#include <ansi.h>
//inherit "/d/taiping/npc/smart_npc"; 
inherit NPC;
int show_me(); 
void create()
{
    set_name("������",({"hua mantian","hua"}));
    set("title",HIW"һ������������"NOR);
    set("long","���������Ѿ�վ�˺ܾ��ˣ�ѩ�׵��·��ϻ���ɳ����ͷ��Ҳ�ѱ�Ⱦ�ƣ�����������
ȴ�ǲ԰׵ģ��԰׵�ȫ��һ˿Ѫɫ��\n");
        set("gender","����");
        set("age",42);
        set("combat_exp", 3500000);

        set("int",22);
        set("cor",30);
        set("cps",20);
        set("str",40);
        
        set("reward_npc", 1);
        set("difficulty", 5);
        set("neili",1000);
        set("max_neili",1000);
        set("force_factor",30);
        
      set("combat_exp", 20000000);
        set("score", 200000);

        set_skill("parry", 120);
        set_skill("dodge", 120);
        set_skill("force", 100);
        set_skill("literate", 100);
	set_skill("sword", 100);
	set_skill("unarmed",80);
	set_skill("changquan",200);
	set_skill("feixian-steps",200);
	set_skill("feixian-sword",250);
	set_skill("jingyiforce",200);
        map_skill("dodge", "feixian-steps");
	map_skill("sword", "feixian-sword");
	map_skill("force", "jingyiforce");
	map_skill("parry", "feixian-sword");
	map_skill("unarmed", "changquan");
        
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.tianwaifeixian" :),
        }) );

        
        set("inquiry", ([
                "������" :      (: show_me :),
                "���Ⱥ" :       (: show_me :),
        ]));
        
        set("death_msg",CYN"\n$N˵������һ���Ҳ����İ��� \n"NOR);     
       /* set("nb_chat_chance", 100);
        set("nb_chat_msg_combat", ([ 
        ]) );           
        set("chat_chance_combat", 1);
        set("chat_msg_combat", ({
             (: auto_smart_fight(20) :),
        }) );*/
           set("chat_chance",1);
        set("chat_msg",({
                "�����컹վ����ҹͬ���ĵط������������ƶ�û�иı����\n"
        }) );                   
        
//        CHAR_D->setup_char(this_object());
//        auto_npc_setup("wang",200,160,0,"/obj/weapon/","fighter_w","lianxin-blade",2);
        
        setup();
        carry_object("/clone/misc/cloth")->wear();  
        carry_object("/d/xinjiang/npc/obj/hua_sword")->wield();
  
    
}  
int show_me(){
        object me,ob;
        
        me=this_player();
        ob=this_object();       
        
        if (me->get_id()=="yekai" || me->get_id()=="hongxue") {
                command("puke");
                command("say ����Ϊ����������ߴ������ģ�");
                return 1;
        }
        
        if (me->query("wanma/����")<5) {
                command("hmm");
                command("say �Һ���û��˵���㣬���ϰ�����ˣ�����������ͷ���������");
                command("say �㻹�����뷨�������������������Ұɡ�");
                tell_object(me,WHT"��������������Ҫ����������������ڱ߳ǵ�����Ϊ"+chinese_number(me->query("wanma/����"))+"�㡣\n"NOR);
                return 1;
        }
        
        message_vision(CYN"$N��$nһ���֣����������´������������ֿڣ��������г���ӭ����\n"NOR,ob,me);
        me->set("wanma/��",1);
        return 1;
}
void die()
{
        int i;
        object killer,owner; 
        if(objectp(killer = query_temp("last_damage_from"))) {
             if(owner=killer->query("possessed")) killer = owner;
             killer->set_temp("wanma/ɱ������_ma", 1);
        }
        
        ::die(); 

}