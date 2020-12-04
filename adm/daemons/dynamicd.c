// copyright from Fengyun.

#include <ansi.h>
#include <command.h>

#define DOOM_PATH "/d/llszhuang"
inherit F_DBASE;

string *additional_room = ({});
string *additional_npc = ({});

// ���п��ܵķ���
string *all_dir = ({
       "north","northeast","northwest","south",
       "southwest","southeast","east","west",    
       "up","down","enter","out",
       "northup","northdown","eastup","eastdown",
       "westup","westdown","southup","southdown",
});

int    i, j, size, grid_size, flag, int_dir;
string *dyna_room, *room_names, dir1, dir2, dir3, dir4;
string rev_dir1, rev_dir2, rev_dir3, rev_dir4, *dirs, *rev_dirs, *cur_exits;
object dyna_npc, *room_object, *old_npc, cur_room;
mixed  *room_list, *npc_list, *temp_list;

int regenerate_map();

void create()
{
       seteuid(ROOT_UID);
       set("channel_id", "ϵͳ����"); 
       CHANNEL_D->do_channel( this_object(), "sys", "��̬��ͼ�Ѿ�������\n");
       call_out("regenerate_map",1);
}

int regenerate_map()
{
        int kk;

        remove_call_out("regenerate_map");
        call_out("regenerate_map", 1800); // regenerate map every 30 mins.

        room_list = get_dir(DOOM_PATH+"/dynamic/*.c");  
        for(kk=0;kk<sizeof(room_list);kk++)
                room_list[kk] = DOOM_PATH+"/dynamic/"+room_list[kk];
        room_list += additional_room;                               

        dyna_room = ({});
        while(sizeof(room_list))
        {
                j = random(sizeof(room_list));
                dyna_room += ({room_list[j]});
                room_list -= ({room_list[j]});
        } // �������λ�����                                             

        size = sizeof(dyna_room);

        CHANNEL_D->do_channel(this_object(),"sys", "��ʼ������������ɽׯ��ͼ��\n");

        room_object = ({});
        for(i=0;i<size;i++)
        {
                if( !(cur_room = find_object(dyna_room[i])) )
                        cur_room = load_object(dyna_room[i]);
                        tell_room(cur_room,
                                  HIY"��ɽׯ���Ĵ������ط�����¡¡��...\n��ʱһ��������ת...\n");
                        cur_room->delete("exits");
                        cur_room->delete("blocks");
                        cur_room->set("no_clean_up",1);
                        room_object += ({cur_room});
        }

        // ��ʼ����·��
        for(i=0;i<size;i++)
        {
                //�����ĸ���ͬ�ķ����
                dirs =  ({      "north","northeast","northwest","south",
                                "southwest","southeast","east","west",    
                                "up","down","enter","out",
                                "northup","northdown","eastup","eastdown",
                                "westup","westdown","southup","southdown",
                        });

                rev_dirs = ({   "south","southwest","southeast","north",
                                "northeast","northwest","west","east",
                                "down","up","out","enter",
                                "southdown","southup","westdown","westup",
                                "eastdown","eastup","northdown","northup",
                           });                  

                int_dir = random(sizeof(dirs));
                dir1 = dirs[int_dir];
                rev_dir1 = rev_dirs[int_dir];           
                dirs -= ({dir1});
                rev_dirs -= ({rev_dir1});
                
                int_dir = random(sizeof(dirs));
                dir2 = dirs[int_dir];
                rev_dir2 = rev_dirs[int_dir];           
                dirs -= ({dir2});
                rev_dirs -= ({rev_dir2});

                if(i>0)
                {
                        (room_object[i])->set("exits/"+dir1,dyna_room[i-1]);
                        (room_object[i-1])->set("exits/"+rev_dir1,dyna_room[i]);
                }
                
                int_dir = random(size);   
                                               
                if( (int_dir != i) && !((room_object[int_dir])->query("exits/"+rev_dir2)) )
                {
                        (room_object[i])->set("exits/"+dir2,dyna_room[int_dir]);
                        (room_object[int_dir])->set("exits/"+rev_dir2,dyna_room[i]);
                }
                int_dir = random(size);
                tell_room(room_object[i],HIW"������ͣЪ�������㷢��һ�ж��Ѿ�����...\n"NOR);
        }                                                   
        (room_object[size-1])->set("exits/south",DOOM_PATH+"/yongdao3");
        (room_object[0])->set("exits/north",DOOM_PATH+"/hall");
        return 1;
}

