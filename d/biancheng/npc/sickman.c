#include <ansi.h>
//inherit "/d/taiping/npc/smart_npc"; 
inherit NPC;
int show_me(); 
void create()
{
        set_name("�ձ���",({"tao baoyi","tao","baoyi"}));
        set("title","��������");
        set("long","�ձ����Ǹϳ��İ�ʽ���Դ�ǰ��ϱ�������ֲֹ�������Ͷҽ��������Խ��Խ�\n");
        
        set("gender","����");
        set("attitude", "friendly");
        set("group","citizen");
        
        set("combat_exp",500000);  
        set("age",42);
                
        set("int",40);
        set("cor",40);
        set("cps",40);
        
        set_skill("unarmed",200);
        set_skill("dodge",150);
        set_skill("parry",160);
        set_skill("force",180);
        set_skill("move",200); 
                
        set("max_neili",200+random(500));
        set("neili",query("max_neili"));
        set("force_factor",30);
        
        
        set("inquiry", ([
                "����" :        (: show_me :),
                "ϱ��" :         (: show_me :),
                "�ֲ�" :         (: show_me :),
                "��" :           (: show_me :),
                "��ҩ" :         (: show_me :),
                "ҩ" :          (: show_me :),
                "ҩ��" :        "��ҩ��Ҫ��������ҩ���ӣ������Ķ�ȥ��ѽ��\n",
                "������" :      "�����Ķ�ȥ��������ѽ��\n",
                "ҩ����" :      "�����Ķ�ȥ��������ѽ��\n",
        ])); 
        set("death_msg",CYN"\n$N�޺޵�˵�����������ݣ������˶����Ź�����\n"NOR);      
        set("nb_chat_chance", 100);
        set("nb_chat_msg_combat", ([
                10: name()+"�е��������˰���ǿ����������������\n", 
        ]) );      
        set("chat_chance_combat", 100);
/*        set("chat_msg_combat", ({
             (: auto_smart_fight(20) :),
        }) );*/
        set("chat_chance",1);
        set("chat_msg",({
//              name()+"�����Դ�����������˵�����������������ǰ�������������ˡ�����\n",
        }) );                   
        
        setup();
        carry_object("/clone/misc/cloth")->wear();    
}   
int show_me()   {
        object me,ob;
        
        me=this_player();
        ob=this_object();
        if (me->query("wanma/��������")) {
                command("say �����������ҩ���ӣ���ϱ�����ڲ��ö��ˣ��������������������С�ӡ�");
                return 1;
        }
        command("say �Դ���ϱ�������ⲡ��Ҳ��֪���˶�����ҽ�����˶��ٷ��ӣ�ȴûʲô�ô���");
        command("say �ҵ��ڵ�����һ�Σ������ڷ��Ƴ��ҵ��ˡ�����٢������������һ��ҩ����");
        command("say ��������ҩ��Ҫ��������ҩ���ӣ������Ķ�ȥ��ѽ��");
        command("cry tao baoyi");
        me->set_temp("wanma/��������",1);
        return 1;
}   
int accept_object(object who, object ob)
{
        if (ob->name()==HIY"������"NOR) {
                command("touch "+who->get_id());
                command("say ̫��л�ˣ��Ҿ���������Ӣ�۵Ĵ����µģ�");
                if (!who->query("wanma/��������")) {
                        who->set("wanma/��������",1);
                        who->add("combat_exp",1000);
                        who->add("potential",200);
                        who->add("wanma/����",1);
                        tell_object(who,HIW"�㱻�����ˣ�һǧ��ʵս���飬���ٵ�Ǳ�ܣ�\n"NOR);
                   tell_object(who,HIW"���������ԶС������������ˣ�\n"NOR);
                } 
                return 1;               
        }
        return 0;
}                        
                                
