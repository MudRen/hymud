// wuchen.c
#include <ansi.h>
inherit NPC;

void create()
{
	set_name("�޳�����", ({"wuchen daozhang", "wuchen", "daozhang"}));
	set("title", HIR"�컨��"HIG"������"NOR);
	set("nickname", HIC "׷�������" NOR );
	set("gender", "����");
	set("age", 52);
	set("long", 
"�������޳����ˡ�����ʱ�켣���֣��ٸ���ƶ�������������ް�����
����ǿ�������ֵ����ڣ��ٸ��κ������á���һ��������һλ�ټ�С
�㣬��Ȼ�������صİ�����������λС��ȴ���޳���û���ģ����˸�
�׽�����һ��ҹ���޳�͵͵������֮ʱ����С��˵���������ȫ�Ǽ�
�⣬û�����ġ����޳���Ȼ���ķ��䡣��С��������������˰���
�����Ļ�������˵�������ô��������һ�Σ��ҿɲ�������Ҫ������
���ң��Ͱ���һ���ְ������ҡ����������۰����ţ�Ҳ����Ҽ�į
�µ������޳�һ�ﲻ������İν����Լ�����ۿ���������С��¥��
����������ٲһ����ӿ�˳������޳���ʹ���ڵأ����ﻹ�ܵ�
�����޳����µ��ֵ��Ǵ��Ⱥ�������Ƴǳأ������ȳ����ְ�С��ȫ
�Ҷ�׽�����������䡣������Ϊ�޳����ǰ����Ƕ�ɱ�ˣ�����Ҫ����
С�������ӡ���֪������С�㣬�ĳ�һ�������˰����ͼ��˶����ˣ�
�Լ���ҹ�����뿪���ǵط����Ļ��������ʹ˳������˵��ˡ�����Ȼ
���˼ң����Ǳ������ƣ����Ǻ������������������컨���ϵ���
����ͤ��������˸��֡�\n");
	set("attitude", "peaceful");
	set("class", "taoist");
	set("per", 21);
	set("str", 21);
	set("int", 30);
	set("con", 26);
	set("dex", 30);

	set("qi", 29000);
	set("max_qi", 29000);
	set("jing", 22000);
	set("max_jing", 22000);
	set("neili", 32500);
	set("max_neili", 32500);
	set("jiali", 100);

	set("book_count", 1);
	set("combat_exp", 15000000);
	set("score", 0);

set_skill("force", 280);
	set_skill("honghua-shengong",280);
	set_skill("dodge", 380);
	set_skill("youlong-shenfa", 280);
	set_skill("hand", 280);
	set_skill("benlei-shou", 280);
	set_skill("parry", 280);
	set_skill("sword", 290);
	set_skill("zhuihun-jian", 390);
	set_skill("literate", 50);

	map_skill("force", "honghua-shengong");
	map_skill("dodge", "youlong-shenfa");
	map_skill("parry", "zhuihun-jian");
	map_skill("sword", "zhuihun-jian");
	map_skill("hand", "benlei-shou");
	prepare_skill("hand", "benlei-shou");

        set("env/wimpy", 60);
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.zhuihun" :),
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :),
        }) );
	setup();
	
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/wudang/obj/greyrobe")->wear();
    
}
