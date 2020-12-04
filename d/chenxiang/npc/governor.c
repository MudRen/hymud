 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
int leave();
void create()
{
        set_name("¬����", ({ "master lu", "master","lu" }) );
        set("long",
                "��͢��פ�ڳ������Ʒ֪�أ���ʿ����������Ϊ����ó�����հ�����\n");
        set("nickname", HIG"ֱ���¸�"NOR);
        set("attitude", "heroism");
            set("rank_nogen",1);
        create_family("��͢����",7,"�������� ֪������");
 
    set("student_title","��Ա");
    set("ranks",({ "׼����","����","����","��ͳ��","ͳ��","��Ӫ��ͳ��",
                       "��Ӫͳ��","��Ӫ��ͳ��","���������ᶼָ��ʹ","�����������ᶼָ��ʹ",
                       "�����׾��������ݺ�","�����׾�������ݺ�","��ǰ���ݺ�",
                       "�����׾�������ָ��ʹ","�����׾������ָ��ʹ","��ǰ��ָ��ʹ",
                       CYN"�����׾�������ָ��ʹ"NOR,CYN"�����׾������ָ��ʹ"NOR,HIC"��ǰ��ָ��ʹ"NOR }));
    set("rank_levels",({ 32000,64000,128000,256000,384000,
                             512000,800000,1024000,1556000,
                             2048000,3652000,5000000,
                             6258000,8848000,10800000,
                             14580000,20048000,26244000 }));    
        set("inquiry", ([
                "leave": (: leave :),
        ]) );
    
        set("vendetta_mark", "authority");
        set("reward_npc", 1);
        set("difficulty", 5);
//        set("str", 27);
        set("cor", 26);
        set("cps", 25);
        set("agi",25);
        set("int",30);
        set("chat_chance_combat", 50);
/*        set("chat_msg_combat", ({
                (: perform_action, "" :),
        }) ); */
        set("combat_exp", 1000000);
        set_temp("apply/damage",500);
 	set_skill("fengmo-zhang",180);
	set_skill("liuhe-zhang",180);
set_skill("dagou-bang",80);
	set_skill("strike",190);
	set_skill("force", 250);             // 
	set_skill("force", 180);             // �����ڹ�
	set_skill("huntian-qigong", 330);    // ��������
	set_skill("dodge", 150);      	     // ��������
	set_skill("xiaoyaoyou", 320);        // ��ң��
	set_skill("parry", 150);             // �����м�
	set_skill("hand", 200);              // �����ַ�

	set_skill("blade", 180);             // ��������
	set_skill("liuhe-dao", 280);       // �������ϵ�
	set_skill("begging", 200);           // �л�����
	set_skill("checking", 200);          // ����;˵
	set_skill("training", 200);          // Ԧ����
	set_skill("strike",285);  // �����Ʒ�

	set_skill("xianglong-zhang",285);

	map_skill("strike","lianhua-zhang");
	prepare_skill("strike","lianhua-zhang");

	
	map_skill("force", "huntian-qigong");
	map_skill("hand",  "suohou-gong");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("blade", "liuhe-blade");
	map_skill("parry", "yuejia-qiang");

	set_skill("yuejia-qiang", 380);        // �򹷰���
	set_skill("suohou-gong", 380);        // �򹷰���
set_skill("chansi-shou", 380);        // �򹷰���
set_skill("claw", 380);        // �򹷰���
set_skill("hand", 380);        // �򹷰���	
set_skill("club", 380);        // �򹷰���		
map_skill("parry", "yuejia-qiang");
map_skill("club", "yuejia-qiang");
map_skill("claw", "suohou-gong");
map_skill("hand", "chansi-shou");

	prepare_skill("hand",  "chansi-shou");
prepare_skill("claw",  "suohou-gong");


       set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "club.gong" :),
                (: perform_action, "club.qldj" :),
                (: perform_action, "club.zhtx" :),
                (: perform_action, "claw.suo" :),
                (: perform_action, "hand.qin" :),                
                (: perform_action, "hand.qinna" :),                
                (: perform_action, "dodge.gjtq" :),                                
                (: perform_action, "dodge.canghaiyixiao" :),                                
                (: perform_action, "dodge.maishou" :),                                
        }) );
        setup(); 
        carry_object(__DIR__"obj/guanfu")->wear();
} 

void init()
{       
        ::init();
        add_action("do_killing", "kill");
    
} 
int do_killing(string arg)
{
    object player, victim;
    string id,id_class;
    player = this_player();
    if(!arg || arg == "") return 0;
    victim = present(arg, environment(player));
    if(!objectp(victim))
                return notify_fail("����û������ˡ�\n");
    if(living(victim))
    {
        id_class=victim->query("class");
        id=victim->query("id");
        if(id_class == "official"&& userp(victim)&& player!=victim)
        {
            message_vision(HIW
"$N�������컯�գ�����Ǭ���������������ھ�ɱ��͢��Ա����������\n"NOR, this_object());
            this_object()->kill_ob(player);
            player->kill_ob(this_object());
            if (!player->is_busy()) player->start_busy(2);
            return 0;
        } 
    }
    return 0;
} 
int leave() {
        if (this_player()->query("class")!="official") return 0;
        message_vision(CYN"$N��ɫ��������Ч��͢���Ҿ�����֮�£���ô�ܰ�;�����ء���\n"NOR, this_object());
        message_vision(CYN"$N˵����ִ��Ҫ����Ҳ����ǿ��ֻ�ǴӴ˾���һ��ƽ�񣬳�֮͢����Ҳ��Ȩ���ʡ�\n"NOR,this_object());
        message_vision(CYN"$N˵����ԧ��ȭҲ������ʹ����˼����˼��\n"NOR,this_object());
   return 1;
}    
