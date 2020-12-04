 //Created by justdoit at May 2001
//All Rights Reserved ^_^ 
 
inherit ROOM; 
void midnight_event();
void sunrise_event(); 
void create() 
{ 
        set("short", "南海码头"); 
        set("long", @LONG 
这里是南海最大的码头，许许多多的海船停靠在此，岸上人来人往，热闹非凡。 
很多人正忙着往船上搬运货物，这些货物将会经海路运往全国各大港口，甚至远赴 
重洋。 
LONG 
           ); 
        set("exits",  
           ([  
             "west"  : __DIR__"beach2", 
            ])); 
         
        set("objects",  
           ([  
             __DIR__"npc/oldfox" : 1, 
             __DIR__"npc/sailor" : 5, 
            ])); 
        set("outdoors", "baiyun"); 
        set("coor/x",30); 
        set("coor/y",-680); 
        set("coor/z",0); 
        setup(); 
      NATURE_D->add_day_event(0, 2, this_object(), (: midnight_event :)); 
}     
void midnight_event() 
{
        object badguy;
        object room = this_object();
        int i, bandit_no = 5 + random(5);
        
        if(!random(10)) {
                for(i=0; i<bandit_no; i++) {
                        if(objectp(badguy = new("/obj/npc/bandit"))) {
                                badguy->setup_bandit("海盗倭寇", "/clone/misc/cloth", "/obj/weapon/blade_guitou", "fy");
                                badguy->move(room);
                                badguy->ccommand("chat 花姑娘，干爸爹！");
                        }
                }
                NATURE_D->add_day_event(3, 1, this_object(), (: sunrise_event :));
} else {
                NATURE_D->add_day_event(0, 2, this_object(), (: midnight_event :));
        }
} 
void sunrise_event() 
{
        object *ob_list;
        int i;
        
        ob_list = children("/obj/npc/bandit");
        for(i=0; i<sizeof(ob_list); i++) {
                if(ob_list[i]->query("area_mark") == "fy") {
                        if(environment(ob_list[i])) {
                                message_vision("$N叫道：八格！八格呀噜！\n",ob_list[i]);
                        }
                        destruct(ob_list[i]);
                }
        }
        NATURE_D->add_day_event(0, 2, this_object(), (: midnight_event :));
}

