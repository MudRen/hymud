#include <ansi.h>
#include <room.h> 
inherit ROOM; 
void create()
{
        set("short", "ɳ�ӵ�");
        set("long", @LONG
ԭ��������һ�����ӣ������ˮ������ȴ������ɳĮ����ΧһƬ�谵��������
�����ɵ�ɳˮ������Ըо���ˮ�е�ɳ�������Ħ���������գ���סһ��������
΢΢������������ȥ��б�Ϸ������и����ڣ�͸��΢΢��⡣ 
LONG
        );
        set("exits", ([ 
                "southup" : __DIR__"sandriver1",
        ])); 
        set("indoors", "quicksand"); 
        set("coor/x",-1100);
        set("coor/y",-10);
        set("coor/z",0);
        setup();
} 
int valid_enter(object me) {
        me->set_temp("in_river", time());
        tell_object(me, "\nͻȻ�䣬ѹ�������ˣ����ܵ���ɳҲ�����ˣ���Ӹߴ����£���ͨһ��������ˮ�\n\n");
        message("vision", "\n��ͨһ����" + me->name() + "�����������Ե�ˮ�С�\n", this_object(), me);
        this_player()->set_temp("marks/ˮʱ", 0);
        call_out("airing", 5, this_player());
        return 1;
}  
int airing(object ob)
{
        int i, htime, ntime;
    
        if( environment(ob) == this_object())    {
                htime = (int)ob->query_str() + (int)ob->query_kar();
                if(!(ntime = (int)ob->query_temp("marks/ˮʱ"))) {  
                        ntime = 5;
                } else {
                        ntime = ntime + 5;
                }
           ob->set_temp("marks/ˮʱ", ntime);
                if( ntime > htime ) {
                        ob->die();
                        ob->set_temp("marks/ˮʱ", 0);
                } else if( ntime > (htime - 15) )
                                message_vision(HIR "$N�Ѿ���ɰ����״̬���ٲ��Ͽ��ˮ���ͻ�����������\n"NOR, ob);
                  else if( ntime > (htime - 30) )
                                message_vision(HIR "$N�Ѿ���������࣬�����֮���ٲ���ˮ�����»�����������\n"NOR, ob);
                  else 
                                message_vision(HIB "$N�����ؿ�Խ��Խ�ƣ������ˮ���Ѵ����˺ܾá�\n"NOR, ob);
        call_out("airing",5, ob);
    }
    return 1;
}   
int valid_leave(object me, string dir) {
        if (dir=="southup") {
                message_vision(HIB"\n$N��ס������������ǰ��ȥ��\n"NOR, me);     
        } else this_player()->set_temp("marks/ˮʱ", 0);
        return 1;
}       
