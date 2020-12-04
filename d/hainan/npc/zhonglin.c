// master.c
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name(YEL"����"NOR, ({ "zhongling", "girl", "dizi" }) );
	set("title", YEL"Сʦ��"NOR);
	set("gender", "Ů��" );
	set("age", 15);
	set("str", 27);
	set("dex", 30);
	set("dex", 27);
	set("int", 24);
                set("max_qi",15000);
        set("max_jing",15000);
        set("max_sen",15000);
        set("neili", 20000);
        set("max_neili", 20000);

        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 600);
        set_temp("apply/damage", 650);
  
set_skill("demon-strike",280);
set_skill("yubi-jian",280);
set_skill("zhuifeng-quan",280);
set_skill("bitao-shengong",280);
set_skill("baihua-zhang",280);
set_skill("feixian-jian",280);
set_skill("qiongya-bufa",280);

        set_skill("literate",280);
        set_skill("unarmed",280);
        set_skill("dodge",290);
        set_skill("parry",280);
	set_skill("force",280);
	set_skill("blade",280);
	set_skill("changquan",280);
	set_skill("strike",280);
	set_skill("cuff",280);
	set_skill("sword",280);
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 600);
        set_temp("apply/damage", 650);

        //set_skill("doomsword",380);
        //set_skill("chilian-shenzhang",380);
        //set_skill("softsword",280);
        //set_skill("nine-moon-sword",380);
        map_skill("strike","baihua-zhang");
        map_skill("cuff","zhuifeng-quan");
        map_skill("sword","yubi-jian");
        map_skill("force","bitao-shengong");
        map_skill("dodge","qiongya-bufa");
        map_skill("parry","yubi-jian");

	prepare_skill("strike", "baihua-zhang");
	prepare_skill("cuff", "zhuifeng-quan");

        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: exert_function, "shield" :),
                (: exert_function, "powerup" :),
                (: exert_function, "roar" :),
                (: perform_action, "sword.kuangwu" :),
                (: perform_action, "sword.feixian" :),
                (: perform_action, "sword.rouqing" :),	
                (: perform_action, "sword.tianwaifeixian" :),	
                (: perform_action, "sword.wan" :),	                	
                (: perform_action, "parry.shi" :),
                (: perform_action, "cuff.hantian" :),
(: perform_action, "cuff.luori" :),
(: perform_action, "cuff.nx" :),
(: perform_action, "cuff.qiankun" :),		             
(: perform_action, "cuff.qin" :),		             
(: perform_action, "cuff.qzwd" :),		             	             
        }) );  
  
	set("force_factor", 3);

	set("long",
		"��������ʦ̫��С��һ������.�˿������а�����һ������֦.
����ؿ�����.\n");
       set("combat_exp", 500000);
	set("score", 2000);
create_family("������", 4, "����");
        set("chat_chance", 10);
        set("chat_msg", ({
        "����Ц�����س���:����,����Ͱ�...... ......��\n",
        "����������������е�����֦,���ﲻ֪�ں�Щʲô��\n",
        "�����ʯ���ϲ��˸�����,������������\n",

"����������:Ϊʲô��֥�鿪��,����������,÷��,����,����,����... ....��\n",
        "����һ�߲�ͣ�����Ÿ���ˮ��,һ�������ͷ��������������Ŀ�ˮ��\n",

"�������˵��:��֪��֪�����������ı�������Щ?\n",
        "���������:��֪���ǰѱ���������ô����\n",
        "���鿴��������:Ϊʲôÿ�춼���˴�����������,��ĺ���ô?\n",
        "�����������������������\n",
        "����˫�ֹ�ͷ,���˸�����:�����ˡ�\n",
        "ʦ��Ϊʲô��׼���ǵ��ٲ�������?\n",
        }));






	set("inquiry", ([
		"out" : "��˵��,�ں�Զ�ĵط�,�и��а���Ͱ͵���,���ҵ���һ������..... ...��",
		"�ٲ�" : "ʦ����׼������㵽��ȥ,Ҳ��֪��Ϊʲô��",
		"����" : "��˵ʦ�������ʱ��,�ڸ����ĺ����еõ���һ�ѱ�����",
		"name": "�ҵ����ֲ��������߱���,����!",
		"here": "�����������з��ֵ�һ��Сɽ��,��ɱ������˵��",
	]) );

	setup();
	carry_object("/d/hainan/obj/taoshuzhi")->wield();
	carry_object("/d/hainan/obj/shaqun")->wear();
       carry_object("/d/hainan/obj/flowershoe")->wear();
}

void attempt_apprentice(object ob)
{
	if ((int)ob->query("age") > 20) 
	{	command("say ���Լ���û��ʦ��,��λ" + RANK_D->query_respect(ob) + ",�����������Ҹ�����!");
		return;
	}
	command("say ��������λ" + RANK_D->query_respect(ob) + "��ɲ�Ҫ���ߺ��\n");
	command("recruit " + ob->query("id") );
        command("say �´�Ҫ����,ֻҪ�������С����˵[֥�鿪��]����.\n");	
}


