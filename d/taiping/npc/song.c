#include <ansi.h>
inherit NPC; 
int curse_me(); 
void create()
{
        set_name("������",({"mother song","song","mother"}));
        set("title","������");
        set("long","
�̺�����Ѻ���Ѫ������Ȼ���ŵú����ᣬ����������������Ҳֻ�����̫�š���
���ϵ�����Ҳʵ�ڹ��࣬����ƹ�бб�������������ϣ�ÿһ�����ƶ����Ű�Ӱ��
�ͺ�����һ��������һͷ��ͷ��ȴ���ںڷ��������Ҳ�Ƶ�������ɢ��\n");
        set("gender","Ů��");
        set("age",72);
        set("no_arrest",1);
        set("no_busy",1);
        set("combat_exp",2700000);
        set("attitude","friendly");
        
        set("death_msg",HIR"\n$N�����е�������Ҳ����ˣ��߳��ž����������� \n"NOR);
        set("nb_chat_chance", 100);
        set("nb_chat_msg_combat", ([
                50:     (: curse_me() :),
        ]) );    
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
             
        }) );
        set("chat_chance",1);
        set("chat_msg",({
                "�������������ŵ�����������û��ʲôֵ�òι۵ġ���\n",   
        }) );
        
        setup();
        carry_object(__DIR__"obj/witchcloth")->wear();
        carry_object("/d/taiping/obj/blackpie");
}  
void die() {
        
        object me, ob, owner;
   ob=this_object();
        
        if(objectp(me=query_temp("last_damage_from") ))     
        if(owner=me->query("possessed")) {
                me = owner;
        } 
        
        if (me)
        if(!me->query("parrot/ɱ������")) {
                me->set("parrot/ɱ������",1);
        }
        ::die();
}  
int curse_me() {
        object ob, *enemy;
        ob=this_object();
        enemy=query_enemy();
        switch (random(3)) {
                case 0: message_vision(HIG"\n$N��Ȼ�ں�����ץ����һ��ħҩ���ſ�������ȥ��\n"NOR,ob);
                        break;
                case 1: message_vision(HIW"\n$N�������ˣ�˻����������������㣬�����µ������ϡ����ϵ�ɽ������\n"NOR,ob);
                        break;
                case 2: message_vision(HIR"\n$N�����૵ز������䡪��������˵���ͣ�һ���ᱻ���������˵�˫�֣�
һ���ᱻն�£�����˵��ĸΣ�һ���ᱻ�ڳ���ι��������\n"NOR,ob);
                        break;
        }       
        foreach (object x in enemy){
                tell_object(x,YEL"��������������䣬�����ͷʹ����Ҫ�ѿ���һ������������\n"NOR);
                x->receive_wound("jing",200,ob);
        }
        return 1;
}  
