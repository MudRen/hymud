inherit ROOM; 
void create() 
{ 
        set("short", "����֮ɭ���"); 
        set("long", @LONG 
ԭʼɭ����Ҷ�Ժ���ǣ�������գ����������ſ�Ҷ����
����֬��ϵ�ζ�������ϵ�̦����Ҷ����ȥ������ģ����滹
����Ұ�޵ĺۼ�������Ũ�ܵ�ɽ���������Էֱ淽��
LONG
); 
                        
        set("outdoors", "forest"); 
        set("virtual_room", 1); 
        set("no_magic",1);
        set("no_npc",1);
        set("exits", ([ /* sizeof() == 3 */ 
                //"west" : __DIR__"maze/entry", 
                "north" : "/d/city/5lt/exit", 	
        ])); 
      set("objects", ([ /* sizeof() == 4 */
  __DIR__"forest_door" : 1,
]));


  
        setup();
        replace_program(ROOM); 
} 

 /* void init()
{
string dest,test;
object obj,me;
	mapping exits;
me=this_player();

	exits = this_object()->query("exits");
dest = exits["west"];
 if (! (obj = find_object(dest)))
{
tell_object(me,"ϵͳ������,������.\n");
dest="/p/migong/shilian/maze";
 if ( (obj = find_object(dest)))
{
destruct(obj);
load_object(dest);
tell_object(me,"ϵͳ����������,������.\n");
}
}
dest=replace_string(dest,"/entry","");
dest=replace_string(dest,"/exit","");
//test=" 1 2 3 ";
//test=replace_string(test, " ", "");

//tell_object(me,"ϵͳ·��"+dest+"��\n");

}*/