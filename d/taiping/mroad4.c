 inherit ROOM;
void create()
{
        set("short", "̫ƽ��С��");
        set("long", @LONG
���������ߣ����Եĵ��̶�������������ġ�ƽ���ϵꡱ���Ǹ���ջ��Ҳ�Ǽ�
���̣�����������ﴫ�����������������������ֵ������ֵ���Ȼ�Ƿ��������һ
������Ҷ��糺��������������糯¶�������ݵ���֬����һ������ͨͨ��С����
���˸������ļ��ˡ�
LONG
        );
        set("exits", ([ 
                "west" : __DIR__"laodian",
                "east" : __DIR__"tiepu",
                "south": __DIR__"mroad45",
                "north": __DIR__"mroad3",
        ]));
        set("outdoors", "taiping");
        
        if (random(3)) {
                set("objects", ([
                        __DIR__"npc/drunk" : 2,
                ]) );
        } else {
                set("objects", ([
                        __DIR__"npc/fakedrunk": 2,
                ]) );
        }
        
        set("item_desc", ([
                    
        ]));
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        
}  
           
