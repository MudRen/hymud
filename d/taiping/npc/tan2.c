#include <ansi.h>
#include <command.h>
inherit NPC;
inherit __DIR__"timeshift"; 
void throw_away(object ob);
int red_stone(); 
void create()
{ 
        set_name("̷�컢",({"tan tianhu","tan"}));
        set("title",YEL"̷�������� �϶�"NOR);
        set("long", "
̷�������쵱Ȼ��̷��Ҳ�����ǲ����Ǳ���̷�ȵĵ�ϵ�����������Լ�Ҫ��ô˵��
��û���˸һ��ɣ�Ҳû���˷��ϡ�ƴ��ʮ�������������˴�С���ٶ��ԡѪ��ս��
��̷�������족ȷʵ���ڽ���������վס�˽ţ����Ƶ����ǵ��ˣ�������ѱ���
��һ����������\n"); 
        set("age",40);
        set("combat_exp", 7500000);
        set("class","swordsman");               
        set("attitude","friendly");
        set("group","tan");
        
        set("resistance/gin",30);
        set("resistance/kee",30);
        set("resistance/sen",30);
        
        set("day_room","/d/taiping/house1a");
        set("dinner_room","/d/taiping/laodian");
        set("shift/dinner_leave","$Nվ������������ȥ��\n");
        set("shift/dinner_arrive","$N���������ܼ��ۣ�������ֵ����¡�\n");
        set("shift/after_dinner","$N����������ʮ�����ӣ�ץ�����һ������������ȥ��\n");
        set("shift/back_dinner","$N�ε��ε����˹���������̷�챪һ�����ȡ�\n");
        
        set("death_msg",CYN"\n$N˵���ϴ��Ϊ�ұ���ġ������������� \n"NOR);             
        set("nb_chat_chance", 100);
        set("nb_chat_msg_combat", ([
                10:     (: red_stone() :),
        ]) );           

                
        setup();
        carry_object(__DIR__"obj/hat")->wear();
        carry_object(__DIR__"obj/lan_cloth2")->wear(); 
} 
void init() {
        
        object ob;
        ::init();
        if( interactive(ob = this_player())) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}  
void greeting(object ob) {
        
        object *inv;
        string my_position;
        if( !ob || environment(ob) != environment()) return;
        my_position=file_name(environment(this_object()));
        if(my_position==this_object()->query("day_room")) {
                command("say ˭��������ģ�����ȥ��");
                call_out("throw_away",10,ob);
        }
        remove_call_out("shifting");
        call_out("shifting", 1, this_object()); 
} 
void throw_away(object ob) {
        if( !ob || environment(ob) != environment() ||is_fighting(ob)) return;
        this_object()->kill_ob(ob);
        ob->kill_ob(this_object());
} 
int red_stone() {
        object me,ob, stone;
        me=this_player();
        ob=this_object();
        if (file_name(environment(ob))!= "/d/taiping/laodian")         return 1;
        message_vision(WHT"\n$NͻȻŭ�������������˫�������߳������Ѳ������ڵ�̷�ȣ�����ȴԶ
��̷�ȸ����������ݺὭ���ĳ���������\n"NOR, ob);
        message_vision(WHT"˭֪$N���Ӹ����𣬾��������꣬�ꡱ�����죬����һ���Һ���\n"NOR,ob);
        message_vision(WHT"$N����ȥʱ�������ȵ�ϥ�ǹؽڴ������ѡ�\n"NOR,ob);
        stone=new("/d/taiping/npc/obj/redstone");
        if (stone) stone->move(ob);
        die();
        return 1;
}         
