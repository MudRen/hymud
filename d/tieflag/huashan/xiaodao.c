 inherit ROOM;
void create()
{
        set("short", "ɽ��С��");
        set("long", @LONG
��һ��·����ƽ��������ɽ�Ͱεض���С·��ɽ��ȵ��̻����У�С·����
��ľï�ܣ��㲻ʱ�������ϻ�ȸ�ö��Ľ�����һ��СϪ������С·��һ�໺����
��ȥ��Ϫˮ�峺���ס�������һƬï�ܵ����֡�
LONG
        );
    set("exits", ([ 
                "westup" : __DIR__"canglong",
            "eastup" : __DIR__"xiaodao1",
                "north" : __DIR__"milin",
        ]));
    set("objects", ([
                __DIR__"npc/woodcutter2" : 1,
        __DIR__"npc/yellowbird" : 1,
    ]));
    set("outdoors", "huashanfy"); 
    set("coor/x",-573);
    set("coor/y",-90);
    set("coor/z",67);
        setup();
} 
void init(){
        if(this_player()->query("marks/��ɽ_��ȸ") && random(20)==0) {
                call_out("bird_come", 2, this_player());
        }
}
void bird_come(object me){
        object obj;
        int i;
        
        if(!interactive(me) || environment(me) != this_object()){
                return;
        }
        obj = new("/d/wolfmount/npc/obj/zhuguo");
        i =random(20);
   if(objectp(obj) && (i == 3 || i == 4)){
                message_vision("\nһֻС��ȸ������$N����������һ�����ɫ�Ĺ��ӡ�\n", me);
                message_vision("���ɫ�Ĺ������£��պ�����$N���С�С��ȸչ��߷ɳ���������\n", me);
                obj->move(me);
        } else {
                obj = new(__DIR__"obj/yihua");
                message_vision("\nһֻС��ȸΧ����$Nͷ�����˼�Ȧ������䵽$N���\n", me);
                message_vision("һ��С����С��ȸ�������£�����$N���С�С��ȸ��������չ���ȥ��\n", me);
                obj->move(me);
        }
        me->delete("marks/��ɽ_��ȸ");
}  
