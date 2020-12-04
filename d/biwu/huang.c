#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void consider();
string ask_me();

void create()
{
    set_name("��ҩʦ", ({"huang yaoshi", "huang", "yaoshi"}));
    set("title", "�һ�����");
    set("nickname", HIY "��а" NOR );
    set("gender", "����");
    set("age", 42);
    set("long", 
        "�������һ����������ºö�ȫ�ɼ��ģ���˱��˳�������а����\n");
    set("attitude", "peaceful");
    set("class", "scholar");
	
    set("str", 121);
    set("int", 130);
    set("con", 126);
    set("dex", 130);
    set("per", 130);

    set("chat_chance", 1);
    set("chat_msg", ({
        "��ҩʦ̾�˿����������� ���� �ض�������ĺ��ӣ���С��û���� ������\n",
        "��ҩʦ��ͷ��˼����Ȼ���\n",
    }));
    set("inquiry", ([
        "����"     : "���ֱ����Ů���Ĺ����� \n",
        "�����澭" : "������ܰ���ȡ���澭�ϲᣬ��һ������л�㡣\n",
    ]));

    set("qi", 355000);
    set("max_qi", 355000);
    set("jing", 353000);
    set("max_jing", 353000);
    set("neili", 353500);
    set("max_neili", 353500);
    set("jiali", 100);

    set("book_count", 1);
    set("combat_exp", 19500000);
    set("score", 0);
	         set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 2500);
        set_temp("apply/damage", 2550);
    set_skill("leg", 1200);             // �����ڹ�
    set_skill("force", 1000);             // �����ڹ�
    set_skill("bibo-shengong", 980);     // �̲���
    set_skill("claw", 1200);              // ����צ��
    set_skill("hand", 1200);              // �����ַ�
    set_skill("finger", 1200);            // ����ָ��
    set_skill("tanzhi-shentong", 980);   // ��ָ��ͨ
    set_skill("unarmed", 1200);           // ����ȭ��
    set_skill("strike", 1200);            // ����ȭ��
    set_skill("luoying-zhang", 980);     // ��Ӣ����
    set_skill("xuanfeng-leg", 980);      // ����ɨҶ��
    set_skill("dodge", 1200);             // ��������
    set_skill("anying-fuxiang", 980);    // ��Ӱ����
    set_skill("parry", 1000);             // �����м�
    set_skill("sword", 1000);             // ��������
    set_skill("luoying-shenjian", 980);  // ��Ӣ��
    set_skill("yuxiao-jian", 980);       // ���｣��
    set_skill("lanhua-shou", 980);       // ������Ѩ��
    set_skill("qimen-wuxing",980);       // ��������
    set_skill("count",1150);              // ��������
    set_skill("literate",1250);           // ����ʶ��
	
    map_skill("force"  , "bibo-shengong");
    map_skill("finger" , "tanzhi-shentong");
    map_skill("hand"   , "lanhua-shou");
    map_skill("unarmed", "xuanfeng-leg");
    map_skill("leg" , "xuanfeng-leg");
    map_skill("dodge"  , "anying-fuxiang");
    map_skill("parry"  , "yuxiao-jian");
    map_skill("sword"  , "yuxiao-jian");
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 2500);
        set_temp("apply/damage", 2500);
  set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: exert_function, "play" :),
                (: exert_function, "roar" :),
                (: perform_action, "dodge.taohaimangmang" :),
                (: perform_action, "hand.fuxue" :),
                (: perform_action, "sword.taohuajian" :),
                (: perform_action, "sword.taohuajian" :),
                (: perform_action, "sword.tianwai" :),                
                (: perform_action, "sword.yuxiao" :),                
                (: perform_action, "strike.shenjian" :),                
                (: perform_action, "strike.xuan" :),                
                (: perform_action, "leg.kuangfeng" :),                
                (: perform_action, "leg.kuangfeng" :),                
                (: perform_action, "finger.huayu" :),                
                (: perform_action, "finger.jinglei" :),                
                (: perform_action, "finger.lingxi" :),                
        }));
    set("inquiry", ([
        "�ؼ�" : (: ask_me :),
        "����ɨҶ�ȷ�" : (: ask_me :),
    ]));


    create_family("�һ���", 1, "����");
    setup();
	
    //carry_object(__DIR__"obj/yuxiao")->wield();
    carry_object(__DIR__"obj/bupao")->wear();
    carry_object("/p/item/ritemtz3/wsword18")->wield();
    carry_object("/p/item/ritemtz3/ahands19")->wear();
   // carry_object("clone/book/jiuyin2");
    
}

