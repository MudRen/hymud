#include <ansi.h>
inherit NPC; 
void create()
{
    set_name("����", ({"gao li","gao"}) );
    set("gender", "����" );
    set("nickname", HIC"����ǹ"NOR);
    set("title", "������ �̿�");
    set("long", "���������·���Զ����������Ӱ������ϴ��ż������������ۣ��ǳ����
��Ϊ�������ڵ����²������ǶԳ��ض��ַ�������ǹ��\n");
        set("attitude", "friendly");
    set("age", 25);
    set("cor", 25);
    set("cps", 25);
    set("combat_exp", 4000000);
    set("class","fugui");
        set("force", 3000);
        set("max_neili", 3000);
        set("force_factor", 50);
        set("reward_npc", 1);
        set("difficulty", 5);
        set("ill_boss",5);
 	set_skill("fengmo-zhang",180);
	set_skill("liuhe-zhang",180);
set_skill("dagou-bang",80);
	set_skill("strike",190);
	set_skill("force", 250);             // 
	set_skill("force", 180);             // �����ڹ�
	set_skill("huntian-qigong", 330);    // ��������
	set_skill("dodge", 150);      	     // ��������
	set_skill("xiaoyaoyou", 320);        // ��ң��
	set_skill("parry", 150);             // �����м�
	set_skill("hand", 200);              // �����ַ�

	set_skill("blade", 180);             // ��������
	set_skill("liuhe-dao", 280);       // �������ϵ�
	set_skill("begging", 200);           // �л�����
	set_skill("checking", 200);          // ����;˵
	set_skill("training", 200);          // Ԧ����
	set_skill("strike",285);  // �����Ʒ�

	set_skill("xianglong-zhang",285);

	map_skill("strike","lianhua-zhang");
	prepare_skill("strike","lianhua-zhang");

	
	map_skill("force", "huntian-qigong");
	map_skill("hand",  "suohou-gong");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("blade", "liuhe-blade");
	map_skill("parry", "yuejia-qiang");

	set_skill("yuejia-qiang", 380);        // �򹷰���
	set_skill("suohou-gong", 380);        // �򹷰���
set_skill("chansi-shou", 380);        // �򹷰���
set_skill("claw", 380);        // �򹷰���
set_skill("hand", 380);        // �򹷰���	
set_skill("club", 380);        // �򹷰���		
map_skill("parry", "yuejia-qiang");
map_skill("club", "yuejia-qiang");
map_skill("claw", "suohou-gong");
map_skill("hand", "chansi-shou");

	prepare_skill("hand",  "chansi-shou");
prepare_skill("claw",  "suohou-gong");


       set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "club.gong" :),
                (: perform_action, "club.qldj" :),
                (: perform_action, "club.zhtx" :),
                (: command("unwield yuejia qiang") :),
                (: command("wield yuejia qiang") :),
                (: perform_action, "claw.suo" :),
                (: perform_action, "hand.qin" :),                
                (: perform_action, "hand.qinna" :),                
                (: perform_action, "dodge.gjtq" :),                                
                (: perform_action, "dodge.canghaiyixiao" :),                                
                (: perform_action, "dodge.maishou" :),                                
        }) );
	setup();
        set("chat_chance", 1);
    set("chat_msg", ({
        HIR "��������Ѫ֮����Ŭ������˫˫��˻������˫����˫���������ҵ���\nҲϹ�ˣ��������У��㡣������Զ���������ġ���\n"NOR,
        HIR"�������˿�Ѫ����ΡΡ�ӻ����ͳ�һ����Ѫ��õ���С�����ޣ�\nһ��һ��Ŭ��������˫˫��\n"NOR,
    }) ); 
    setup();
    carry_object(__DIR__"obj/taocloth")->wear();
    carry_object(__DIR__"obj/bravespear")->wield();
    carry_object(__DIR__"obj/bloodrose");
    carry_object(__DIR__"obj/doll");
} 
int accept_object(object who, object ob){
        object xi, box;
        if(ob->query("id") == "jadebox" && ob->name() == "ȸ�����"){
                message_vision("$N�������Ѫ���е�$n����ȸ������������$n���У��������������һ������\n", 
                                who, this_object()); 
                who->start_busy(3);
                if(!present("ximen yu", environment())){
                        return 0;
                }
                if(present("ximen yu", environment()) && present("shuang shuang", environment())){
                        xi = present("ximen yu", environment());
                        call_out("kill_xi", 2, who, xi);
                } else if (present("ximen yu", environment()) && !present("shuang shuang", environment())){
                        message_vision("$N��̾һ�������ˣ�̫���ˡ���\n", this_object());
                        message_vision("$N���г�ǹ��ת�����Լ��Ŀڡ�������\n", this_object());
                        box = new(__DIR__"obj/jadebox");
                        if(objectp(box)){
                                box->move();
                        }
                        call_out("dead", 1);
                        return 1;
                }
                return 1;
        }
   return 0;
} 
int kill_xi(object me, object xi){
        if(!interactive(me) || environment(me) != environment()){
                return 0;
        }
        message_vision(RED"\n$N������������ȭͷ�����˲���ǵ���Ѫ��ͻȻŭ��һ������ֱ��������ǹ���֡�\n"NOR,
                        this_object()); 
        message_vision("$NĬĬ�����ۻ����е�˫˫��������������ȵ������ţ���ǹ��\n",
                        this_object()); 
        message_vision(HIW"\n$N������ǹ�·𼲵�����֡�������\n", this_object()); 
        message_vision(HIW"        ��ǹ�������������� ���ۡ���һ�������ѹᴩ����������ʺ�\n\n"NOR,
                        this_object()); 
        xi->killed(me); 
}  
void dead(){
        this_object()->die();
} 
void do_leave(object me){
        call_out("leave", 1, me);
} 
void leave(object me){
        object shuang;
        
        if(!interactive(me) || environment(me) != environment()){
                if(present("shuang shuang", environment())){
                        shuang = present("shuang shuang", environment());
                        message_vision("$N�����ű���˫˫����ʧ�ںڰ�֮�С����� \n", this_object());
                        destruct(shuang);
                        destruct(this_object());
                }
                return;
        }
        if(present("shuang shuang", environment())){
                shuang = present("shuang shuang", environment());       
                message_vision("$N����$n���˵�ͷ��Ȼ�������ű���˫˫����ʧ�ںڰ�֮�С�����\n",
                                this_object(), me); 
                if(!me->query("m_success/�ɾȸ���")){
                        me->add("score", 300);
                        me->add("combat_exp", 1000);
                   me->add("potential", 100);
                        me->set("m_success/�ɾȸ���", 1);
                }
                destruct(shuang);
                destruct(this_object());
        }
        return;
}  
