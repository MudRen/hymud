#include <ansi.h>
inherit NPC;
void smart_fight();
void smart_busy();
void smart_attack(); 
void create()
{
    set_name( "������", ({ "wang ruolan", "wang","ruolan" }) );
        set("long", "��������������ͷ�Ķ���Ů����Ҳ�ǵ������ǹ����Ψһ���ˡ�
һϮ���£��Գ�����͹���µĽ�����ġ�һ����ˮ���˫��������Թ�����Ŷ�ϲ��\n");
        set("attitude", "friendly");
        set("title", HIM "�绨����"NOR);
        set("age", 17);
        set("gender", "Ů��" );
        set("cor", 40);
        set("cps", 25);
        set("per", 60);
        set("class","fugui");
        set("combat_exp", 4000000);
        set("reward_npc", 1);
        set("difficulty", 5);
        
        set("resistance/kee",30);
        set("resistance/gin",20);
        set("resistance/sen",30);
        
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: smart_fight() :),    
        }) ); 
        set("force",1000);
        set("max_neili",1000);
        set("force_factor",100);
        
	set("qi", 25000);
	set("max_qi", 25000);
	set("jing", 22400);
	set("max_jing", 22400);
	set("neili", 58000);
	set("max_neili", 58000);
	set("jiali", 300);
	
	set("combat_exp", 8000000);
	set("score", 200000);
	set("shen", 100000);
	 
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
                (: perform_action, "claw.suo" :),
                (: perform_action, "hand.qin" :),                
                (: perform_action, "hand.qinna" :),                
                (: perform_action, "dodge.gjtq" :),                                
                (: perform_action, "dodge.canghaiyixiao" :),                                
                (: perform_action, "dodge.maishou" :),                                
        }) ); 
        
        setup();
        carry_object(__DIR__"obj/white_cloth")->wear();
        carry_object(__DIR__"obj/gold_spear")->wield();
        add_money("gold", 5);
} 
int accept_object(object me, object obj)
{
        object book;
        if( (string) obj->query("name") == HIR"����ǹ"NOR)
        {
                message_vision("$N��$n���˸��򸣣�\n",this_object(),me);
                command("smile");
                command("say ��л��λ" + RANK_D->query_respect(me) + "�����һ��˶�ʧ�İ���ǹ��\n");
                
                if (me->query("m_killer/�鶫��")) {
                        command ("say ��Ϊ��л���Ȿ����ǹ�ף����͸����ɣ�");
                        book = new(__DIR__"obj/bw_book");
                        if(book) book->move(me);
                        book = new(__DIR__"obj/spear_book");
                        if(book) book->move(me);
                        message_vision("$N�ӻ����ͳ�����ǹ���͸�$n��\n",this_object(),me);
                } else
                        message_vision("$N�ƺ���ӻ�����Щʲô���������ܣ���ԥ��һ����ͣס�ˡ�\n",this_object());
                if(!me->query("m_success/������ǹ"))
                {
                        me->add("score",100);
                        me->set("m_success/������ǹ",1);
                }
           return 1;       
        }
        else
        {
                command("lean");
                command("say ��л��λ" + RANK_D->query_respect(me) + "��ʲô�Ҷ���Ҫ��ֻҪ��������߾ͺá�\n");
                return 0;
        }  
        return 1;
} 
