#include <ansi.h>
inherit NPC;
int answer_robery();
int answer_di();
int answer_yang();  
void create()
{
        set_name("����ү", ({ "hua siye","hua","siye" }) );
        set("long",
                "����ү��ǰ�������׸������øߴ󡢷�׳�����ཱུ�һ������͸�ųϿҡ�
���ģ��ƺ���һ���թ��û�С����˿̣����Ĺ�������ȴ������������
���˸е�����������\n"); 
        set("attitude", "friendly");
        set("title", "��������");
        set("age",53);
        set("cps", 77);
        set("agi", 60);
        set("class","wudang");
        
        set("combat_exp", 4000000+random(500000)); 
        set("force",1000);
        set("max_neili",1000);
        set("force_factor",30);
        
        set_skill("unarmed",200);
        set_skill("taiji-quan",800);
        set_skill("parry",400);
        set_skill("dodge",400);

        map_skill("unarmed","taiji-quan");

        
        set("chat_chance", 1);
        set("chat_msg", ({
"����ү��ҵ�����������߻ص��������롣���һ���������Ҳ����Ź��㡣����\n"
}) ); 
        set("inquiry", ([
                "���ڰ�" : (: answer_robery :),
                "robery" : (: answer_robery :),
                "���" : (: answer_yang :),
                "yang" : (: answer_yang :),
                "yang zheng" : (: answer_yang :),
                "������" : (: answer_di :),
                "di" : (: answer_di :),
                "di qinglin" : (: answer_di :),
        ])); 
        setup(); 
        carry_object("/clone/misc/cloth")->wear();
} 
int is_ghost() { return 1; } 
int answer_di()
{
        object me;
        string msg;
        
        me=this_player();
    msg=HIR"����үԹ����˵��������Ϊ�����ݣ��в��������������м��мǡ�\n"NOR;
        me->set("libie/���_����ү������",1);
//      if (me->query(marks/��𹳶�))
//              msg+=HIR"����ү˵������
        message_vision(msg,me);
        return 1;
} 
int answer_robery()
{}
int answer_yang()
{}
