#include <ansi.h>
//inherit "/d/taiping/npc/smart_npc"; 
inherit NPC;
int show_me();
int finished(); 
void create()
{
        set_name("����",({"tao shi","taoshi","tao"}));
        set("title","����һϢ");
        set("long","�ձ���ϱ������ǰ�����ϵķص���ȥ���˴ι��ţ������͵����ֲֹ���������
�á�Ҳ��֪Ͷ�˶���ҽ�����˶���ҩ������Խ��Խ���ȴһ��û��ɫ���˿�
�������ڴ���շת������\n");
        
        set("gender","Ů��");
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
        
        set("death_msg",CYN"\n$N˵�������˾Ͳ����ٻ�Ǯ��ҩ�ˡ�����\n"NOR);      
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
                (: finished() :),
        }) );                   
           
        setup();
        carry_object("/clone/misc/cloth")->wear();     
} 
int finished() {
        object tao1,tao2; 
        tao1=this_object();
        tao2=present("tao baoyi",environment(tao1));
        if (!tao2) {
                command("say ���壬���壬��������ѽ��");
                return 1;
        }else {
                command("say ���尡���ҡ��������ǲ����ˡ����㻹�ǳ�������׼�����°ɡ���");
                message_vision("$N������$nҴ�ñ���˵���������Ϸ��Ƴ�����ץ������ҩ�����˾ͺ��ˡ���\n",tao2,tao1);
        }
        return 1;
}
        
        
                   
