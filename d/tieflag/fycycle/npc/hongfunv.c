 inherit NPC;
#include <ansi.h>
#include <combat.h>
void create()
{
        set_name("������Ů", ({ "redcloth girl","girl" }) );
        set("gender", "Ů��" );
        set("class", "legend" );
        set("age", 21);
        set("str", 30);
        set("per", 40);
        set("cor", 20);
        set("cps", 20);
        set("con", 30);
        set("int", 30);
        set("max_qi", 6000);
        set("max_jing", 5000);
        set("max_sen", 5000);
        set("max_neili", 5000);
        set("neili", 6000);
        set("fle", 20);
        set_temp("apply/attack", 100);
        set_temp("apply/damage", 50);
        set("long", "һ������ȥ��ʮ�������Ů������ͤͤ�������ݣ�
���վ�ã������з糾֮ɫ����һ��Ӣ��������Ľ���ѡ�\n");
        set("chat_chance", 1);
        set("chat_msg", ({
    "������Ů����������ͷ��һ�Բ�����\n",
                }) );
// take out her perform because it has problem with fight check
/*        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: perform_action, "sword.caidiekuangwu" :),
                (: perform_action, "dodge.luoyeqiufeng" :),
                (: perform_action, "iron-cloth.bingwantianzhang" :),
        }) ); */
        set("combat_exp", 300000);
        set("attitude", "friendly");
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
        set("no_arrest", 1);
        setup();
        carry_object("/d/fugui/npc/obj/redcloth")->wear();
        carry_object("/d/loulan/obj/sword")->wield();
} 
void win_enemy(object obj){
        object qiuran;
        qiuran = present("qiuran han", environment(this_object())); 
        if(objectp(qiuran)){
                qiuran->win_fight(obj);
        }
} 
void lose_enemy(object obj){
        object qiuran;
        qiuran = present("qiuran han", environment(this_object())); 
        if(objectp(qiuran)){
                qiuran->lose_fight(obj);
        }
} 
int accept_fight(object me){
        if(this_object()->is_fighting()){
                message_vision("$N����$nһ�ۣ�΢΢һЦ�����ٴ�Ƭ�̡�\n", this_object(), me);
                return 0;
        }
        if(me->query_temp("marks/fight_hongfunv")) {
                message_vision("$Ņ��ͷ������$nһ�ۣ����˸��򸣵����룡\n", this_object(), me);
        me->delete_temp("marks/fight_hongfunv");
        return 1;
        } else {
                return 0;
        }
} 
void die()
{
    object me;
    
    if(me=query_temp("last_damage_from")){
            message_vision("$N�������Ծȥ��΢һ��������ɫ�ָֻ��˺���\n",this_object(),me);
    } 

    "/cmds/imm/full"->main(this_object(),"");
} 
void unconcious()
{
        die();
}      
