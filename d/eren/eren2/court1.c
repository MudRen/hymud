 inherit ROOM;
void create()
{
        set("short", "��ʯ·");
        set("long", @LONG
��·���ˣ�һ���ӿ��������������ߣ�������ģ�������ɴ��ƺ�
���и��Ҷ�����ϧ����̦��ס�ˡ�������������һ���ֲ�ڣ���ʯ·����
�򶫱����죬��߶�����ʯ·��������������ȥ�ġ�
LONG
        );
        set("exits", ([ 
                "westup" : __DIR__"exit1",
                "eastdown" : __DIR__"court2",
                "southeast" : __DIR__"yongdao7",
                        ]));
        set("item_desc", ([
        "��̦" : "��ɫ����̦�����˶��ڡ�\n",
        "moss" : "��ɫ����̦�����˶��ڡ�\n",
        "�Ҷ�" : "�Ҷ��ܸߣ����������ȥ�ǲ����ܵġ�\n",
        "cave" : "�Ҷ��ܸߣ����������ȥ�ǲ����ܵġ�\n",
    ]));
        
        set("objects", ([
                __DIR__"npc/guarda" : 2,
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
        if((dir == "westup" || dir == "eastdown" )&& !obj->query("wizard")){
                inv = all_inventory(this_object());
                for (i=0;i<sizeof(inv);i++){
                        if (userp(inv[i]) ||!inv[i]->is_character()
                                ||inv[i]->is_corpse()) 
                                        continue;
                   if (inv[i]->query("dungeon_npc")=="eren2")
                                return notify_fail(inv[i]->name()+"���ֵ�ס�����·��\n");
                }
        }       
        return 1;
}
