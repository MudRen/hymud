inherit ROOM;
void create() 
{ 
    set("short", "��"); 
    set("long", @long
����ߵ������ƽ���������ϣ��������£���������ʱ�����
Ҫ�õ�����������������Ĳ�֪ˤ�����ת�˼����������һ��
ʯ̨��ӭ�����и����֡�ͣ���� 
long 
    ); 
    /*set("item_desc", ([ 
        "��̶":  "��̶�������ף���ʱ����С��Խ��ˮ�档\n", 
        "pond":  "��̶�������ף���ʱ����С��Խ��ˮ�档\n", 
    ])); */
    set("exits", ([ 
    		"east": __DIR__"midao",
    		"south": __DIR__"midao",
    		"west": __DIR__"midao",
    		"north": __DIR__"midao",
        ])); 
    set("indoors","shanxi"); 
set("coor/x",-460);
        set("coor/y",-260);
        set("coor/z",100);
        setup(); 
} 
void init() 
{ 
   add_action("do_around", "around"); 
   add_action("do_stop", "stop"); 
} 
 
int do_around(string arg) 
{ 
   object me, room; 
   int i; 
    
   string *rooms = ({"alou2", "alou2a", "alou2b", "alou2c"}); 
   i = random(4); 
   me = this_player(); 
   tell_object(me, "��ת��תȥ��Ҳû�ҵ����ڣ�������·����\n\n"); 
   room = find_object(__DIR__ + rooms[i]); 
   if(!objectp(room)) room=load_object(__DIR__ + rooms[i]); 
   me->move(room); 
 
   return 1; 
} 
int do_stop(string arg) 
{ 
   object me; 
   /*int i; 
    
   string *rooms = ({"alou2", "alou2a", "alou2b", "alou2c"}); 
   i = random(4); */
   me = this_player(); 
   tell_object(me, "���վͣ����Ȼ����վ�ŵ���ʯ̨�͵����³�������Ȼ��͵���һ�������ε�ʯ�ݡ�\n\n"); 
   /*room = find_object(__DIR__ + rooms[i]); 
   if(!objectp(room)) room=load_object(__DIR__ + rooms[i]); */
   me->move(__DIR__"alou3"); 
    return 1; 
} 
