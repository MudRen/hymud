#include <ansi.h>


inherit NPC;


mixed  try_to_learn_waibagua();

void create()
{
        set_name("����̫", ({"shang laotai", "shang", "laotai"}));
        set("gender", "Ů��");
        set("title", "�̼ұ���������");
        set("age", 41);
        set("long", @LONG
����һλ��ĸߴ�ĸ��ˣ��������࣬������
���������ǡ����Ե����̽����ķ��ˣ�����Ů
ʱ������ɷ����ϴ���������ΪŮ�к��ܡ�
LONG);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 45);
        set("int", 30);
        set("con", 30);
        set("dex", 30);

        set("qi", 23600);
        set("max_qi", 23600);
        set("jing", 22800);
        set("max_jing", 22800);
        set("neili", 24000);
        set("max_neili", 24000);
        set("jiali", 160);
        set("combat_exp", 3500000);
        set("score", 10000);

          set_skill("force", 300);
        set_skill("dodge", 250);
        set_skill("finger", 250);
        set_skill("parry", 250);
        set_skill("strike", 250);
        set_skill("sword", 250);
        set_skill("blade", 250);
        set_skill("literate", 260);
        set_skill("mahayana", 500);
        set_skill("buddhism", 500);
        set_skill("jinding-zhang", 250);
        set_skill("tiangang-zhi", 250);
        set_skill("huifeng-jian", 250);
        set_skill("yanxing-dao", 250);
        set_skill("zhutian-bu", 250);
        set_skill("linji-zhuang", 250);
        set_skill("bagua-dao", 250);
        set_skill("bagua-zhang", 250);
set_skill("unarmed", 250);
        set_skill("huixin-strike", 250);
        set_skill("piaoxue-hand", 250);
        set_skill("yinlong-whip", 250);
        set_skill("yitian-jian", 250);
        set_skill("whip", 220);
        set_skill("hand", 220);
        map_skill("force","linji-zhuang");
        map_skill("finger","tiangang-zhi");
        map_skill("dodge","zhutian-bu");
        map_skill("strike","jinding-zhang");
        map_skill("sword","huifeng-jian");
        map_skill("blade","bagua-dao");
        map_skill("parry","bagua-dao");
          map_skill("hand","piaoxue-hand");
        map_skill("strike","bagua-zhang");

//        prepare_skill("strike", "bagua-zhang");

	set_skill("zhuihun-biao", 280);
		set_skill("liuxing-biao", 280);
	set_skill("pili-biao",250);
	set_skill("force", 350);
	set_skill("biyun-xinfa", 280);
	set_skill("dodge", 350);
	set_skill("qiulinshiye", 280);
	set_skill("strike", 250);
	set_skill("unarmed",280);
	set_skill("biye-wu", 280);
	set_skill("parry", 280);
	set_skill("throwing", 280);
	set_skill("zimu-zhen", 280);
	set_skill("literate", 250);
	
	set_skill("dusha-zhang", 280);
	set_skill("lansha-shou", 280);
	set_skill("hand", 280);
	set_skill("strike", 280);
	map_skill("strike", "dusha-zhang");
	map_skill("hand", "lansha-shou");
	map_skill("force", "biyun-xinfa");
	map_skill("dodge", "qiulinshiye");
	map_skill("strike", "dusha-zhang");
	map_skill("unarmed","biye-wu");
	map_skill("parry", "biye-wu");
	map_skill("throwing", "zimu-zhen");
	map_skill("strike", "dusha-zhang");
	map_skill("hand", "lansha-shou");
	prepare_skill("strike", "dusha-zhang");
	prepare_skill("hand", "lansha-shou");
	


	set("chat_chance_combat", 68);
	set("chat_msg_combat", ({
		(: perform_action, "throwing.poqizhen" :),
		(: perform_action, "throwing.dinhun" :),
                (: perform_action, "throwing.qizigangbiao" :),
                (: perform_action, "throwing.tanghua" :),
		(: perform_action, "parry.wandu" :),
		(: perform_action, "parry.meng" :),
		(: perform_action, "strike.tianxie" :),
		(: perform_action, "strike.hantian" :),
		(: perform_action, "hand.canglong" :),
		(: perform_action, "hand.xiangyi" :),
		(: perform_action, "hand.luanpo" :),									
						
	}) );

        set("no_teach", ([
                "bagua-dao" : "���Ե������ҷ�����Դ��ڡ�",
        ]));

        set("class", "fighter");

        create_family("�̼ұ�", 3, "��������");
        set_temp("apply/defense", 100);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 500);
        set_temp("apply/attack", 100);
        setup();

        carry_object("/d/tangmen/obj/zimuzhen")->wield();
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/d/city/npc/obj/yaoshi")->wear();

}

