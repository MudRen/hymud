 inherit NPC;
#include <ansi.h> 
void create()
{
        set_name("����Ӣ", ({ "zhou zhongying", "zhou"}) );
        set("nickname", HIR "����ׯׯ��"NOR);
        set("vendetta_mark","shaolin");
        set("gender", "����" );
        set("age", 44);
        set("per", 25);
        set("int",28);
        set("str",40);
        set("attitude","friendly");
        
        set("max_neili", 1000);
        set("force", 1000);
        set("force_factor",90); 
        set("long",
                "����ׯׯ�������ˣ����˶���΢΢��Щ�����⣬��Ŀ���ȥ������\n��׳С���ǡ�\n"
        );
        set("chat_chance", 1);
        set("chat_msg", ({
        name()+"һ��һ�ֳ�������ʵ���벻�����ڼ�ԭ�������㣭�٣�������࣡��\n",
        }) );
        
        set("combat_exp", 4000000);
        set("resistance/kee",40);
        set("resistance/gin",40);
        set("resistance/sen",40);
        set("no_busy",5);
        
       set("max_qi", 35000);
	set("max_jing", 35000);
	set("neili", 35000);
	set("max_neili", 35000);
	set("jiali",100);
	set("combat_exp", 8000000);
	set("score", 700000);

	set_skill("force", 300);
	set_skill("honghua-shengong", 380);
	set_skill("dodge", 200);
	set_skill("youlong-shenfa", 380);
	set_skill("hand", 300);
	set_skill("benlei-shou", 380);
	set_skill("cuff", 200);
	set_skill("baihua-cuocuff", 380);
	set_skill("strike", 200);
	set_skill("heisha-zhang", 380);
	set_skill("throwing", 200);
	set_skill("wuying-feidao", 380);
	set_skill("blade", 200);
	set_skill("qiuge-dao", 380);
	set_skill("sword", 200);
	set_skill("luohua-jian", 380);
	set_skill("zhuihun-jian", 380);
	set_skill("parry", 200);
	set_skill("literate", 100);
	set_skill("medicine", 380);
		set_skill("painting", 380);


 set_skill("bainiao-jian", 380);
	map_skill("force", "honghua-shengong");
	map_skill("dodge", "youlong-shenfa");
	map_skill("cuff", "baihua-cuocuff");
	map_skill("hand", "benlei-shou");
	map_skill("strike", "heisha-zhang");
	//map_skill("throwing", "wuying-feidao");
	map_skill("sword", "bainiao-jian");
	//map_skill("blade", "qiuge-dao");
	map_skill("parry", "baihua-cuocuff");
	prepare_skill("cuff", "baihua-cuocuff");
	prepare_skill("hand", "benlei-shou");
	set_temp("apply/attack",190);
	set_temp("apply/defense",190);
	set_temp("apply/armor",1500);
	set_temp("apply/damage",1500);


	set("no_get",1);
	set("chat_chance_combat", 90); 
	set("chat_msg_combat", ({
(: perform_action, "dodge.yunlong" :),				
		(: perform_action, "cuff.cuo" :),
		(: perform_action, "hand.yunkai" :),
		(: exert_function, "recover" :),
		(: exert_function, "powerup" :),
	}) );
        
        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object(__DIR__"obj/flag");
}    
void unconcious()
{
	die();
}
void die()
{
	int i;
        object who = this_object()->query_temp("last_damage_from");
  	if (!who) return;

                if ((int)who->query("jinyong/book9")==1)
{
                i = 500+random(2000);
		who->set("jinyong/book9",2);
		who->add("combat_exp",i+12000);
		who->add("potential",i*18);
		who->add("mpgx",10);
		who->add("expmax",2);
		//command("chat "+this_player()->query("name")+"��ɫ���ˣ������Ƕ�ԡ�");
		tell_object (who,"��Ӯ����"+chinese_number(i+12000)+"�㾭��"+
		           chinese_number(i*18)+"��Ǳ��"+"ʮ�����ɹ��� ����ɳ����ޣ���\n");
		message_vision("$N����Χ���˺���������̩�����ˣ���̩�����˻���˵������ȥ�ؽ��컨���ܶ��ˡ�\n",this_object(),who);
		
		who->save();
}		
		
	::die();

}                         