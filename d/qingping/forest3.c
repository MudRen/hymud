 inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
������һƬ��ֵ����֣���ľ�����Ƿǳ����ܼ����������������͸����ľ
��ҫ������Ȼ����ȴ���Եĸо���һ������Ľӽ���������Ϣ���ּ�û���κο�
�Ա��ϵĵ�·����о�����ǰ�ľ�����ʱ��ض��ڱ仯�ţ����ѷֱ�ʲô����ʲ
ô�ǻá���
LONG
        ); 
        set("outdoors","qingping");
        set("coor/x",230);
        set("coor/y",2000);
        set("coor/z",0);
        setup();
} 
void init(){ 
    string *rooms = ({"forest1", "forest2", "forest3", "forest4", "forest5", "forest6"});
    string *direction = ({"north", "south", "east", "west", "northeast", "northwest", "southeast", "southwest"});
        if(this_object()->query("exits")){
                delete("exits");
        }
    set("exits/"+direction[random(8)], __DIR__ + rooms[random(6)]);
        set("exits/"+direction[random(8)], __DIR__+rooms[random(6)]);
}
int valid_leave(object me, string dir){
        object room; 
        if(me->query("class") == "shenshui" && (dir=="north" || dir=="south" || dir=="east" || dir=="west"
                        || dir=="northeast" || dir=="northwest" || dir=="southeast" || dir=="southwest")){
                tell_object(me, "�㲻����ǰ�������Ի������ǰ�С�\n");
                room = find_object(__DIR__"forest4");
                if(!objectp(room)){
                        room = load_object(__DIR__"forest4");
                }
                me->move(room);
                return notify_fail("");
        }
        return 1;
} 
