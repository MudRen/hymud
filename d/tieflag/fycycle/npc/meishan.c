 inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void do_leave();
void create()
{
    set_name("��ʿ", ({ "wen shi", "zhen zhen"}) );
    set("gender", "����" );
    set("age", 35);
    set("int", 30);
    set("per", 30);
    set("long",
        "��ƽ����ѩ���ϣ���׼���û��һ˿Ѫɫ�����Ǹմ������ķ�
Ĺ���߳����Ƶġ���Ϣ���ƺ���û����Ϣ����֪������û�оȡ�\n" 
        );
    set("max_jing", 3000);
    set("max_qi", 3000);
    set("max_sen", 3000);
    set("eff_jing", 30);
    set("eff_qi", 30);
    set("eff_sen", 30);
    set("jing", 3000);
    set("qi", 3000);
    set("sen", 3000);
    set("max_neili", 3000);
    set("neili", 3000); 
    set("combat_exp", 9999999);
    set_skill("unarmed", 100);
    set_skill("sword", 180);
    set_skill("force", 200);
    set_skill("move", 100);
    set_skill("literate", 100);
    set_skill("dodge", 100);
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
//              "��ѩ���ӣ���ʿ�����ż���������ʿ�������ں����ﲻס�ض����š�\n", 
//              "��������ʿ���Ϸ���һ˿Ц�⣬��Ц�����ж���ů�ġ�\n", 
        }) ); 
        set("cured", 0); 
        set("answered", 0);
    setup();
    carry_object("/clone/misc/cloth")->wear();
    
}
 
void init(){ 
        ::init();
        if(find_call_out("do_leave") == -1 && !query("cured")) {  
                call_out("do_leave", 120); 
        }  
        if(find_call_out("do_selfcure") == -1 && !query("cured")) { 
                call_out("do_selfcure", 30); 
        } 
} 
 
void do_selfcure(){ 
        if(query("cured")) { 
                return; 
        } 
        message_vision("$N���ֱۻ����ض���һ�¡�\n", this_object()); 
        message_vision("$NŬ���ع������ľ�����վ������������Ȼվ�Ĳ��ȣ�������վ���ŵġ�\n", 
                        this_object()); 
        set("long",  
                "��������ô����㲶�˥������׼���û��һ˿Ѫɫ�����Ǹմ������ķ�
Ĺ���߳����Ƶģ��������峿���͵ķ��ѩ��������ز��ȶ���
��Ȼ����ֱͦ��վ�ţ�Ȼ��ȴ����ʱ��������� \n" 
   ); 
        set("cured", 1); 
} 
void do_leave(){ 
        message_vision("\n$N���ų��صĲ���������ȥ��ѩ��������һ��������㼣��\n", this_object()); 
        destruct(this_object()); 
} 
 
int Cured(object me){ 
        if(!query("cured")) { 
                message_vision("$N��Ϊ���ѵ���������������������������$n��������֪������˭�𡣡�  
���������򡡣���󣯣�\n",  
                                this_object(), me);      
                set("long",  
                "��������ô����㲶�˥������׼���û��һ˿Ѫɫ�����Ǹմ������ķ�
Ĺ���߳����Ƶģ��������峿���͵ķ��ѩ��������ز��ȶ���
��Ȼ����ֱͦ��վ�ţ�Ȼ��ȴ����ʱ��������� \n" 
                ); 
                add_action("do_answer", "answer"); 
                set("cured", 1); 
                remove_call_out("do_leave"); 
                call_out("do_leave", 60); 
        } 
} 
 
int do_answer(string arg) { 
        object me; 
        me = this_player(); 
        if(!arg || (arg != "yes" && arg != "no")) { 
                return 0; 
        } 
        if(query("answered")){ 
                return 0; 
        } 
        if(arg == "yes") { 
                message_vision("$N΢΢һЦ���������¾��������������\n", me); 
                message_vision("$N�������ã���Ȼ��ˣ�����һ��Ҳ֪�����������ҡ�����һ�����ձص��ر�����\n", 
                                this_object()); 
                me->set("marks/÷ɽ��", 1); 
                do_leave(); 
   } else if(arg == "no") { 
                message_vision("$N��ɫãȻ��ҡ��ҡͷ��\n", me); 
                if(me->query("title") == "��ͨ����") { 
                        message_vision("$Nע����$n��Ц�������������$N˵����������Ը�������ң��ɵ�where find me��\n", this_object(), me); 
                        me->set("marks/÷ɽ��", 3); 
                        do_leave(); 
                } else { 
                        message_vision("$N�������������������������Ե������л����\n", this_object()); 
                        me->set("marks/÷ɽ��", 2); 
                        do_leave(); 
                } 
        } 
        return 1; 
} 
     
