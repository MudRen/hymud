 inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
�ƿ��ţ����Ǽ仨�������õ����룬�������ӣ���������ֻ����ɫ��
���룬������ֻ�յú��ļ�������������ϣ����ż����ˡ��⼸����Ȼ
�������ˣ�������ȴ�ֺ�Ů�����ƣ�ÿ���˶���������������
LONG
        );
        set("exits", ([ 
                "northwest" : __DIR__"bedroom1",
                "north" : __DIR__"bedroom2",
                "south" : __DIR__"palace3",
                "east" : __DIR__"corridor",
                        ]));
        set("objects", ([
                __DIR__"npc/girl1" : 1,
                __DIR__"npc/girl3" : 1,
                __DIR__"npc/baiyi" : 2,
        ]) );
        set("indoors", "eren");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
} 
int valid_leave(object obj, string dir){
        int i;
        object *inv;
        if(dir == "north"){
                inv = all_inventory(this_object());
                for (i=0;i<sizeof(inv);i++){
                        if (userp(inv[i]) ||!inv[i]->is_character()
                                ||inv[i]->is_corpse()) 
                                        continue;
                        if (inv[i]->query("dungeon_npc")=="eren2")
                                return notify_fail(inv[i]->name()+"˵��������æ���ء�\n");
                }
        }       
   return 1;
} 
