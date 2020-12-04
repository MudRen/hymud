 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors. 
inherit ROOM;
void create()
{
        set("short", "ɱ��ׯ");
        set("long", @LONG
�ߵ������ɫ��Ȼһ����һ����ɭɭ�ڳ�����ɱ�������Ŵ˴���
�Ͽա���ǰȥ��һ������Ĵ�Ժ���Ӳоɵ��ż��Ͽ��Կ������������
��������������˻�ӭ���������ǹ�ȥ�������ֻԻ�����ֻʣ����ҡ
ҡ��׹�ġ�����ׯ�����ң���ǰ�п���������ľ�ƣ�����һ�顣
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : "/d/city/qionghuajie",
  "west" : __DIR__"qyuan",

   ]));
        set("item_desc", ([
                "sign": @TEXT
һ�龯���ƣ�����д�ţ�
����
����������һ
������������
�����ԡ�����
������������

TEXT
        ]) );  

        set("no_magic",1);
        set("NONPC",1);

        set("objects", ([
        
        __DIR__"npc/zanghua" : 1,
                        ]) );

        set("outdoors", "sharen");
        set("no_death_penalty",1);
        set("coor/y",-430);
        set("coor/z",0);
        set("coor/x",5);
        setup();
} 
    
int valid_leave(object me, string dir)
{
    object *inv;
    object ob;
    int i;
    int birdbox=0;

    if( dir == "east" && ob=present("ji zanghua", this_object()))
    {
        inv = all_inventory(me);
        for(i=0; i<sizeof(inv); i++)
        {
            if( (string)(inv[i]->query("id")) == "bird box")
            {
                tell_object(me,ob->name()+"ɵЦ�ŵؽ�������Ⱦ��Ѫ����"+
                            inv[i]->name()+"���˻�ȥ��\n\n"); 
                destruct(inv[i]);
                return 1;
            }
            if( (string)(inv[i]->query("id")) == "corpse")
            {
                tell_object(me,ob->name()+"����ҡ��ҡͷ��������ʬ�嶼��ɱ��ׯ�Ĺ�������ܴ��ߡ���\n"+ob->name()+"����ؽ������ϵ�"+
                            inv[i]->name()+"����������������С�\n\n"); 
                destruct(inv[i]);
                return 1;
            }
        }  
    }
    return 1;
}   