//NPC /d/henshan/npc/tian.c
#include <ansi.h>
inherit NPC;

void create()
{
	seteuid(getuid());
	set_name("�ﲮ��", ({ "tian boguang", "tian" }));
        set("title","�ɻ�����");
        set("nickname",HIY"ǧ��ɻ��Ҷ���"NOR);
        set("long", 
                "�����ǽ�����һ������\n"
                "һ������еȵ�׳�����ӣ�ü���۽Ǵ�����������֮�⣬��ʱ��������ۡ�\n");
	set("gender", "����");
	set("age", 37);
	set("attitude", "friendly");
	set("shen_type", -1);

        set("per", 23);
	set("str", 25);
	set("int", 24);
	set("con", 25);
	set("dex", 26);

	set("pubmaster",1);
	set("qi", 20000);
	set("max_qi", 20000);
	set("jing", 20000);
	set("max_jing", 20000);
	set("neili", 20000);
	set("max_neili", 20000);
	set("jiali", 10);

	set("combat_exp", 3500000);
	set("score", 40000);

	set_skill("blade", 220);
	set_skill("dodge", 220);
	set_skill("parry", 220);
	set_skill("force", 220);
	set_skill("lingxu-bu", 220);
	set_skill("touch", 220);
	set_skill("kuangfeng-blade", 220);
         
	map_skill("cuff", "touch");
	map_skill("unarmed", "touch");
	map_skill("dodge", "lingxu-bu");
	map_skill("parry", "kuangfeng-blade");
	map_skill("blade", "kuangfeng-blade");

	set("chat_chance_combat", 80);
	set("chat_msg_combat", ({
		(: perform_action, "blade.kuang" :),
		
	      }) );
	set("chat_chance", 10);
	set("chat_msg", ({
		"�ﲮ��Ц�������Ҳû��ϵ�����ͷ���������¾���С�����ˡ�\n",
                "�ﲮ��̾�������Դ����˲�����ͺ¿�����������ѹ����������أ���֪���տ����١�\n",
                "�ﲮ�����������죬����˭�ܰ����Ҹ�椾ͺ��ˡ�\n",
                 "�ﲮ�ⴹͷɥ����˵����Ҳ��֪������Ժ����������ʲô�»�ɫ��\n",
                 "�ﲮ���Ȼ����һ�񣺡�ǰ����·��ɽ��С�壬�Ǹ��д��ĳ��Ŀ�������Ĳ�����\n",
	}) );

	setup();
	carry_object("/d/baituo/obj/baipao")->wear();
	carry_object("/clone/weapon/gangdao")->wield();
}
