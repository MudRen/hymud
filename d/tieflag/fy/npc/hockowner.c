#include <ansi.h>
inherit NPC;
#include <ansi.h>
//inherit F_PAWNOWNER;
inherit F_VENDOR;
int growup(); 

void create()
{
        set_name("����", ({ "xiangling" }) );
        set("gender", "Ů��" );
    set("nickname", HIM"��������"NOR );
        set("age", 29);
        set("title", "�����ϰ���");
        set("long",
                "�����С������ǧ��¥��������࣬�����Ƴ������˻��ģ�
�ձ�һ�������У�ȢΪ��ʮ�˷�С���š�\n");
        set("combat_exp", 50000);
        set("attitude", "friendly");
        set("per",30);
        set("no_arrest",1);
        
    set("resistance/kee",50);
    set("resistance/sen",50);
    set("resistance/gin",50);

        set_skill("unarmed",200);
        set("richness",99999999);
        set_skill("dodge",200);
        
        setup();
        carry_object(__DIR__"obj/hua_skirt")->wear();
} 
void init()
{       
        object ob; 
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }

} 
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        if ( ob->query("gender") == "����")
{
        switch( random(5) ) {
                case 0:
message_vision("$N����������˵�������������ϣ�������λ"+RANK_D->query_respect(ob)+
"����ɶ�����������������ˣ�\n",this_object(),ob); 
                        break;
                case 1:
message_vision("$N��ǰ��ס$n���֣�Ц�����˵������λ"+RANK_D->query_respect(ob)+
"����������ϴ������ʱ���ߴ����ͣ�Ӣ�������ˣ���\n",this_object(),ob);
                        break;
                                }
}
        else
{
        switch( random(5) ) {
                case 0:
message_vision("$N��ǰ�ḧ$n�ķ�����˵������λ"+RANK_D->query_respect(ob)+
"����������£����������ˣ�\n",this_object(),ob); 
                        break;
                                }  
}               
} 
int accept_object(object who, object ob)
{
        message_vision("$N��$n˵����л�ͣ���\n",this_object(),who);
                return 1;
}
               
void die(){
        object me,staff;
        object owner,room;

        

        
        if(objectp(me=query_temp("last_damage_from") ))     
        if(owner=me->query("possessed")) {
                me = owner;
        } 

        message_vision("\n\n$N���ˡ�", this_object());
        message_vision("\n\n$N��ʬ��˲�丯�࣬�ݷ��Ѿ����˺ܾúܾúܾá�����\n\n"NOR, this_object());
        if (me) 
        CHANNEL_D->do_sys_channel("info",sprintf("%s��%s����ǧ������ı�ƺ���������", NATURE_D->game_time(),me->query("name")) ); 
        
        staff=new(__DIR__"obj/hua_skirt");
        staff->move("/d/tieflag/fy/qianyin");
        destruct(this_object());
}  
void reset ()
{
	        set("richness",99999999);
}      
