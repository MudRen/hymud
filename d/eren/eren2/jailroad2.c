 inherit ROOM;
void create()
{
        set("short", "�ص�");
        set("long", @LONG
����Ѳ���˵�ǵ�·��ֻ��һ����ʪ�ֻ��ĵص��������ܵͣ�������
����ͨ��������������Ҷ����ڹ�¡�˵ز�֪��ǳ��û��һյ�ƣ�û��һ
�����죬����ϤϤ����������С����ܹ���ż���ȵ�������֨��һ����С�
LONG
        );
        set("exits", ([ 
                "south" : __DIR__"jailroad1",
                "north" : __DIR__"jailroad3",
                "east" : __DIR__"jail2",
        ]));
        set("objects", ([
                __DIR__"npc/star_pig" : 1,
                __DIR__"npc/star_dog" : 1,
        ]) );
        set("indoors", "eren2");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
}  
int valid_leave(object obj, string dir){
        int i;
        object *inv;
        if(dir == "north" || dir=="east"){
                inv = all_inventory(this_object());
                for (i=0;i<sizeof(inv);i++){
                        if (userp(inv[i]) ||!inv[i]->is_character()
                                ||inv[i]->is_corpse()) 
                                        continue;
                        if (inv[i]->query("dungeon_npc")=="eren2")
                                return notify_fail(inv[i]->name()+"���������������ˡ�\n");
                }
        }       
        return 1;
}
