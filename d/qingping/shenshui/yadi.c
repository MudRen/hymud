 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "�µ�");
        set("long", @LONG
ʯͷ�Ǻ�ɫ�ģ����ƺ�Ҳ�Ǻ�ɫ�ģ���ͷ���µ׵�ʯͷ�Ͻ������ɫ��ˮ
�������þ�����Ҳ���Ѳ�����ͷ��������ֻ�о����˵׵�ˮ���ƺ��Ƚ�ƽ�ȡ�����
Ȼ�����������������޷�����ġ�
LONG
        );
    set("outdoors","shenshui");
    set("coor/x",190);
    set("coor/y",12310);
    set("coor/z",-70);
    setup();
} 
void init(){
        if(interactive(this_player())){
                call_out("do_flush",30,this_player());
        }
        add_action("do_dive", "dive");
} 
void do_flush(object me)
{
        object room; 
        if(!me || environment(me) != this_object()) {
                        return;
        }
        tell_object(me,"\nͻȻһ�����˰�����˳�ȥ��\n\n");
        room = find_object(__DIR__"ocean1");
        if(!objectp(room)) room= load_object(__DIR__"ocean1");
        me->move(room);
 
}  
int do_dive(){
        object me, obj; 
        me = this_player();
        message_vision("$Nһ������������ˮ�С�\n", me);
        obj = find_object(__DIR__"midsea");
           if(!objectp(obj)) {
                obj = load_object(__DIR__"midsea");
        }
        me->move(obj);
        message("vision", me->name() + "��������ߵ�ˮ�С�\n", environment(me), me);
        return 1;
}       
