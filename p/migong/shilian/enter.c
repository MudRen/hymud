inherit ROOM; 
void create() 
{ 
        set("short", "试炼之森入口"); 
        set("long", @LONG 
原始森林树叶苍黑如盖，遮天蔽日，林中弥漫着枯叶腐烂
和树脂混合的味道，地上的苔鲜落叶踩上去软绵绵的，上面还
布满野兽的痕迹，四周浓密的山雾，让人难以分辨方向。
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
tell_object(me,"系统有问题,处理中.\n");
dest="/p/migong/shilian/maze";
 if ( (obj = find_object(dest)))
{
destruct(obj);
load_object(dest);
tell_object(me,"系统还是有问题,处理中.\n");
}
}
dest=replace_string(dest,"/entry","");
dest=replace_string(dest,"/exit","");
//test=" 1 2 3 ";
//test=replace_string(test, " ", "");

//tell_object(me,"系统路径"+dest+"。\n");

}*/