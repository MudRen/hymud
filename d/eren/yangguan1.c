 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "��Į");
        set("long", @LONG
����ǰ�ߣ�ɳĮ�ޱ��޼ʣ�����ããһƬѩ��ʲôҲû�У���һ������Ҳ�Ҳ�
����Զ����������Ⱥɽ��������ѩ����������ֱ����ʡ�������������ж�����
���ߣ�٪��Ҳ����˾��ˣ�������������ж��������ߣ�����Ҳ�����٪�塣
LONG
        );
        set("exits", ([ 
        "northwest" : __DIR__"yangguan2",
        "southeast" : __DIR__"yangguan",
        ]));
        set("objects", ([
                __DIR__"obj/sand": 1,
        ]) );
        set("outdoors", "eren");
        set("coor/x",-970);
        set("coor/y",120);
        set("coor/z",0);
        setup();
} 
int valid_leave(object obj, string dir){
        int i;
        object *inv;
        if(userp(obj) && (dir == "northwest" || dir == "southeast") && obj->query_temp("eren/haha_4")){
//              if (!find_living("sandworm")) return 1;
                if (!random(3)) {
                        message("vision",YEL"���µ�ɳ�Ӻ�Ȼ����������"+obj->query("name")+"һ��վ�Ų�ס��ֱ���»�ȥ��\n"NOR,this_object());
                        message_vision(YEL"$N����Խ��Խ����Ȳ�������������ͷ������\n"NOR,obj);
                        obj->start_busy(2);
                        call_out("enter_sand",3,obj); 
                        return notify_fail(""); 
                }       
        } else if (userp(obj) && random(3)) {
                obj->move(this_object());
                return notify_fail("");
                }
   return 1;
}   
void enter_sand(object obj) {
        object room;
        room = find_object(__DIR__"sandtrap");
        if(!objectp(room)) 
                room = load_object(__DIR__"sandtrap");  
        obj->move(room);
        tell_object(obj,YEL"ͨ��һ�������ƺ�������ʵ�ء�\n"NOR);        
} 
