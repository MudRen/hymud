 // chuenyu.c
inherit NPC; 
string kill_passenger(object who); 
void create()
{
        set_name("���ڻ�̫", ({ "chunyu" }) );
        set("gender", "����" );
        set("title", "���ڱ���");
        set("age", 47);
        set("str", 27);
        set("int", 12);
        set("per", 10);
        set("max_qi", 2000);
        set("long", @LONG
���ڻ�̫��ǿ����������ʱ��ҽ��ᣬ�޶�����������
�Զ��磬û��Ը����Ϊͽ�������������������ټ�֮������
��һ��
LONG
);
        set("attitude", "killer");
        set("reward_npc", 1);
        set("difficulty", 2);
        set("combat_exp", 80000);
        set("bellicosity", 3000 );
        set("chat_chance", 50);
        set("chat_msg", ({
"���ڻ�̫�ȵ���߾���㾹�һ���ү�ĺ��£�\n",
         }) );
      set("max_qi", 29000);
        set("max_jing", 29000);
        set("neili", 36000);
        set("max_neili", 36000);
        set("jiali", 100);
        set("combat_exp", 5500000);
        set("score", 500000);
        set("box_count",1);
        set("tieshao_count",1);

        set_skill("force", 300);
        set_skill("wudu-shengong", 380);
          set_skill("dodge",300);
          set_skill("wudu-yanluobu",380);
          set_skill("unarmed",300);
          set_skill("qianzhu-wandushou",380);
          set_skill("parry",300);
          set_skill("sword",300);
          set_skill("wudu-goufa",380);
          set_skill("poison",300);
          set_skill("literate",200);
          set_skill("finger",290);
          set_skill("shedu-qiqiao",380);
        set_skill("wudu-yanluobu", 380);
        set_skill("unarmed", 260);
        set_skill("qianzhu-wandushou", 380);
        set_skill("parry", 250);
        set_skill("duji", 300);
        set_skill("sword", 280);
        set_skill("wudu-goufa", 380);
        set_skill("poison", 380);
        set_skill("literate", 200);
        set_skill("finger",230);
        set_skill("shedu-qiqiao",380);
	set_skill("whip",500);
	set_skill("chilian-shenzhang",380);
	set_skill("jueqing-bian",380);
 	set_skill("ruanhong-zhusuo",380);
	set_skill("dusha-zhang", 380);
	set_skill("lansha-shou", 380);
	set_skill("hand", 380);
	set_skill("strike", 380);
	map_skill("strike", "dusha-zhang");
	map_skill("hand", "lansha-shou");
	prepare_skill("strike", "dusha-zhang");
	prepare_skill("hand", "lansha-shou");
        map_skill("poison","shedu-qiqiao");
        map_skill("finger","shedu-qiqiao");
        map_skill("force", "wudu-shengong");
        map_skill("dodge", "wudu-yanluobu");
        map_skill("unarmed", "qianzhu-wandushou");
        map_skill("parry", "wudu-goufa");
        map_skill("sword", "wudu-goufa");
map_skill("whip", "ruanhong-zhusuo");
//      map_skill("hammer", "jinshe-chui");
	prepare_skill("strike", "dusha-zhang");
	prepare_skill("hand", "lansha-shou");
         set("chat_chance_combat", 99);
         set("chat_msg_combat", ({
                (: perform_action, "whip.bohu" :),
                (: perform_action, "whip.pan" :),
                (: perform_action, "whip.teng" :),
                (: perform_action, "whip.suo" :),
                (: perform_action, "unarmed.qzwd" :),
                (: perform_action, "dodge.snake" :),
                (: exert_function, "recover" :),
		(: perform_action, "strike.tianxie" :),
		(: perform_action, "strike.hantian" :),
		(: perform_action, "hand.canglong" :),
		(: perform_action, "hand.xiangyi" :),
		(: perform_action, "hand.luanpo" :),		
        }) );
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 200);
        set_temp("apply/attack", 200);
        set("score", 100); 
        setup(); 
        add_money("silver", random(10)); 
        carry_object(__DIR__"obj/chwhip")->wield();
        carry_object(__DIR__"obj/cundan");
}
void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) ) {
        message_vision("���ڻ�̫�ȵ���߾���㾹�һ���ү�ĺ��£�\n",ob);
                kill_ob(ob);
        }
}      
