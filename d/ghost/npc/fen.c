#include <ansi.h>
inherit NPC; 
void create()
{
        object          biao, bag; 
        set_name("������", ({ "fen yan zi", "fen" }) );
        set("nickname", "����̤��");
        set("title", "���");
        set("gender", "����");
        set("age", 27);
        set("per", 30);
        set("combat_exp", 50000);
        set("long",
                "һ����Ů���̺������һ����ü�����ķۺ�ɫ����\n�ۺ�ɫ�������ԣ�б����һ֧�ۺ�ɫ�����ҡ�\n"
        );
        set("no_arrest",1);
      set_skill("zhuihun-biao", 380);
		set_skill("liuxing-biao", 380);
	set_skill("pili-biao",380);
	set_skill("force", 350);
	set_skill("biyun-xinfa", 380);
	set_skill("dodge", 350);
	set_skill("qiulinshiye", 380);
	set_skill("strike", 250);
	set_skill("unarmed",280);
	set_skill("biye-wu", 380);
	set_skill("parry", 280);
	set_skill("throwing", 380);
	set_skill("zimu-zhen", 380);
	set_skill("literate", 250);
	
	set_skill("dusha-zhang", 380);
	set_skill("lansha-shou", 380);
	set_skill("hand", 380);
	set_skill("strike", 380);
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


	set("chat_chance_combat", 98);
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
        setup();
        biao = new(__DIR__"obj/biao");
        bag = new(__DIR__"obj/bag");
        biao->move(bag);
        bag->move(this_object());
        carry_object(__DIR__"obj/biao")->wield();
} 
void init()
{
        object          me; 
        ::init();
        if( interactive(me = this_player()) && !is_fighting() ) {
                call_out("greeting", 1, me);
        }
} 
int greeting(object who)
{
        object          env; 
        env = environment();
        if(present("ye gu hong", env)) {
                say( HIY "\n�������������´�����" + who->name() + "��Ҷ�º�˵������������ҵģ��Ҳ�����������\n"NOR);
                say( HIY "Ҷ�º�����¶������Ż�µı���˵��������Ů���㶼Ҫ��\n"NOR);
                say( HIY "������Ц��Ц������ʱ�������㶼��Ҫ��\n\n"NOR);
        }
        return 1;
}      
