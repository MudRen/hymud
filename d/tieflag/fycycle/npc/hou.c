inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void do_leave();
void create()
{
        set_name("���꺺��", ({ "hou", "hou er"}) );
        set("gender", "����" );
        set("age", 50);
        set("int", 25);
        set("per", 23);
        set("long",
                "һ���������������꺺�ӡ�\n"
                );
        
         set("inquiry", ([
                "�������": 
"������������׿�ڣ����л���䣬������ʣ����ҿ��ֺ��䵱������������˵��ıֻ���������ˣ������˻��ﲻ������\n",
        ]));
                
        set("max_jing", 10000);
        set("max_sen", 10000);
        set("jing", 10000);
        set("sen", 10000);
        set("max_neili", 3000);
        set("neili", 3000);
        set("force_factor",120);
        set("combat_exp", 20000000);
    set("qi", 29000);
    set("max_qi", 29000);
    set("jing", 18000);
    set("max_jing", 18000);
    set("neili", 53500);
    set("max_neili", 53500);
    set("jiali", 100);

    set("book_count", 1);
    set("combat_exp", 9000000);
    set("score", 0);
	 
    set_skill("leg", 380);             // �����ڹ�
    set_skill("force", 280);             // �����ڹ�
    set_skill("bibo-shengong", 380);     // �̲���
    set_skill("claw", 200);              // ����צ��
    set_skill("hand", 320);              // �����ַ�
    set_skill("finger", 320);            // ����ָ��
    set_skill("tanzhi-shentong", 380);   // ��ָ��ͨ
    set_skill("unarmed", 280);           // ����ȭ��
    set_skill("strike", 280);            // ����ȭ��
    set_skill("luoying-zhang", 380);     // ��Ӣ����
    set_skill("xuanfeng-leg", 380);      // ����ɨҶ��
    set_skill("dodge", 280);             // ��������
    set_skill("anying-fuxiang", 380);    // ��Ӱ����
    set_skill("parry", 200);             // �����м�
    set_skill("sword", 320);             // ��������
    set_skill("luoying-shenjian", 380);  // ��Ӣ��
    set_skill("yuxiao-jian", 380);       // ���｣��
    set_skill("lanhua-shou", 380);       // ������Ѩ��
    set_skill("qimen-wuxing",380);       // ��������
    set_skill("count",380);              // ��������
    set_skill("literate",380);           // ����ʶ��
	  set_skill("chixin-jian", 380);             // �����ڹ�
    set_skill("canglang-bian", 380);             // �����ڹ�
    set_skill("whip", 380);             // �����ڹ�
    map_skill("strike"  , "luoying-zhang");
    map_skill("force"  , "bibo-shengong");
    map_skill("finger" , "tanzhi-shentong");
    map_skill("whip"   , "canglang-bian");
    map_skill("hand"   , "lanhua-shou");
    map_skill("unarmed", "xuanfeng-leg");
    map_skill("leg" , "xuanfeng-leg");
    map_skill("dodge"  , "anying-fuxiang");
    map_skill("sword"  , "chixin-jian");
    map_skill("parry"  , "luoying-zhang");    	

if (random(3)==0)
{
    	prepare_skill("strike", "luoying-zhang");
	prepare_skill("leg", "xuanfeng-leg");
}
else
{
	prepare_skill("finger", "tanzhi-shentong");
	prepare_skill("hand", "lanhua-shou");	
}
        set("chat_chance_combat", 99);
        set("chat_msg_combat", ({
                (: exert_function, "play" :),
                (: exert_function, "qimenzhen" :),
                (: exert_function, "roar" :),
                (: perform_action, "dodge.taohaimangmang" :),
                (: perform_action, "hand.fuxue" :),
                (: perform_action, "strike.shenjian" :),                
                (: perform_action, "strike.xuan" :),                
                (: perform_action, "strike.pikong" :),                
                (: perform_action, "leg.wuying" :),                
                (: perform_action, "leg.kuangfeng" :),                
                (: perform_action, "finger.huayu" :),                
                (: perform_action, "finger.jinglei" :),                
                (: perform_action, "finger.lingxi" :),                
		(: command("unwield yuxiao") :),
		(: command("wield yuxiao") :),
		(: command("unwield bian") :),
(: command("wield bian") :),
(: perform_action, "finger.ding" :), 
	(: perform_action, "finger.zhuan" :), 
(: perform_action, "sword.muyu" :),                
	(: perform_action, "sword.nosword" :),                
		(: perform_action, "sword.trhy" :),                
		(: perform_action, "whip.duoming" :),                
		(: perform_action, "whip.lang" :),                
		(: perform_action, "whip.tlyj" :),                
		(: perform_action, "whip.yljx" :),                									
 
        }));

        
        
        set("chat_chance", 1);
        set("chat_msg", ({
        
        }) );
        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/gangjian")->wield(); 
} 
void init(){
        object ob;
        
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 2, ob);
    }
} 
void greeting(object ob){
        message_vision("$N������$nһ�£�����˿��û���κα��顣\n", this_object(), ob);
        if(ob->query("marks/÷ɽ��")) {
        if(ob->query("m_killer/����") && ob->query("m_killer/��������")
                && ob->query("m_killer/��������") && ob->query("marks/л����"))
                tell_object(ob, "����һ��΢С������˵������ȥ�鷿���ƿ�����ש�������衡������壩���£������ѧ
���޵еĹ���\n");             
}
}           