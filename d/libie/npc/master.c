 // master.c
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
        set_name("��һ��", ({ "master yichen", "master", "master lan" }) );
        set("nickname", HIC "������"NOR);
        set("gender", "����" );
        set("reward_npc", 1);
        set("difficulty", 40);
        set("no_heal",1);
        set("age", 54);
        set("str", 50);
        set("cor", 30);
        set("cps", 30);
        set("int", 30);
        set("per", 30);
        set("agi",25);
        set("skill_public",1);
        
        set("attitude","friendly");
        set("max_neili", 15000);
        set("force", 15000);
        set("force_factor", 50);
        
        set("max_qi",99999999);
        set("max_jing",999999);
        set("max_jing",999999);
        set("eff_qi",999999);
        set("qi",999999);
        set("combat_exp", 10000000);
        set("score", 200000);
        
        set("chat_chance", 1);
        set("chat_msg", ({
                "��һ����ɫ���������������һ���ֵ�������ж�����ԡѪ���飬\n��Ȼ̤���������������ȥ�ɡ���ĳ��������̤�����ְ벽��\n",
        }) ); 
        set("long",
"
�����ͷ���Ŷ�������ң����ĺܵ͡�������ס��üë��ס���۾���
��һ���������������ҵ���Ӱ�һ�������Ѿ���ϥ���ϡ�
\n"
        ); 
        create_family("��ɽ����", 3, "����");
        
        set("����",0);
        
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

        set("ranks",({"����","��ū","����","����","��ʦ",
                      "����","����","����","�󻤷�",
                      "����","����","����"}));
        set("rank_levels",({ 32000,64000,128000,256000,512000,
                             1024000,1536000,2304000,3456000,
                             5187000,26244000 })); 
        setup();
        carry_object(__DIR__"obj/bluesword")->wield();
        carry_object(__DIR__"obj/shirt")->wear(); 
} 
 
 
int accept_object(object who, object ob)
{
if(ob->query("name") == "����һ������" ) {
if(query("����")) {
        message_vision(HIY"��һ����Ŷ����һ��������ô����һ�����ŵģ��ѵ��Ǽ�ð�Ĳ��ɣ���\n",this_object());
        return 1;
}       
if(ob->query("������")==who)
{
    message_vision(HIY "��һ����Ŷ����һ�������������İ��Ȼ��̾������㣬��$N���˵�ͷ������
����ʵΪ���ˣ��粻����������ĳ��ɴ�������ѧ���������»��м������������
���͡�����ľ������������ʾӡ�������Ѷ�������δ������ɹ�Щ������ȥ��\n"NOR,this_player()); 
        who->set_temp("libie/���_���ųɹ�",1);
        set("����",1);
        return 1;
}
else
{
    say(HIR"��һ�������˵���������������߹������Լ���ƭ�ң�ȴҲû��ô���ס�\n"NOR);
        kill_ob(who);
        return 1;
}
}
return 0;
} 
int recognize_apprentice(object ob)
{
        if(ob->query("libie/���_ɱ��������"))
                return 1;
}  
void reset()
{
        if(query("����")) {
                add("����",1);
                if (query("����")>8) set("����",0);
        }
}      
