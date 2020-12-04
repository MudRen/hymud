#include <ansi.h> 
#include <armor.h>

inherit ARMOR;

string *du=({
"ice_poison",
"ill_dongshang",
"ill_fashao",
"ill_kesou",
"ill_shanghan",
"ill_zhongshu",
"xx_poison",
"cold_poison",
"flower_poison",
"rose_poison",
"x2_poison",
"sanpoison",
"scorpion_poison",
"qx_snake_poison",
"anqi_poison",
"yf_poison",
"nx_poison",
"chilian_poison",
"yufeng_poison",
"insect_poison",
"xscold_poison",
});

string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});  
void create()
{
	      set_name("[1;32m����֮����[2;37;0m��", ({ "newbie armor", "armor" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("long", @LONG
[1;32m����֮����[2;37;0m����һ�����ޱȼ�Ӳ�ľ��ּ���[1;33m����[2;37;0m�Ƴɣ���һ��������Ǯ��[1;32m����֮����[2;37;0m��
�ۺ�����[37m������˫[2;37;0m �������ޱȼ�̣�����[36m��С[2;37;0m�ķ�������
����һ���������Ʒ ��������:
����:[1;32mһ��[2;37;0m ��ʯ:[1;32m����[2;37;0m ��ʯ:[1;32m����[2;37;0m
����:[1;32m����[2;37;0m ����:[1;32m����[2;37;0m ����:[1;32m����[2;37;0m  ����:[1;32m����[2;37;0m ����:[1;32m����[2;37;0m ����:[1;32m����[2;37;0m 
����һ���������Ʒ ��������:
ˮ:[1;32m����[2;37;0m ��:[1;32m����[2;37;0m ��:[1;32m����[2;37;0m 
������� ����ѧϰ���书 ����д�� (literate)
LONG
);
    set("no_get",1);
	  set("no_put",1);
	  set("no_pawn",1);
	  set("no_give",1);
	  set("no_drop",1);
	  set("no_beg",1);
	  set("no_steal",1);
	  set("systemmake",1);
		set("value", 1800);
		set("armor_prop/intelligence",6);
		set("armor_prop/strength",0);
		set("armor_prop/karey",0);
		set("armor_prop/percao",0);
		set("armor_prop/dexerity",0);
		set("armor_prop/constitution",0);
    set("armor_prop/dodge", 2);
    set("armor_prop/parry", 2);
    set("armor_prop/attack", 2);


    set("armor_prop/armor", 200);
    set("armor_prop/defense", 2);
    
    set("armor_prop/neili", 0);
    set("armor_prop/qi", 3);
    set("armor_prop/jing", 3);
    set("armor_prop/jingli", 3);
    set("armor_prop/damage", 0);

    set("wtypeA",0);
    set("wtypeB",0);
    set("wtypeC",1);
    set("wtypeD",0);
    set("wtypeE",0);
    set("wtypeF",1);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",1);
    set("wtypeK",0);
    set("wtypeL",0);
    
    
                set("skill", ([
                        "name": "literate",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 80,              
                ]) );		


		set("material", "default");
    set("sharpness", 12);
        }
        setup();
}



#include "/obj/ritem/armorzy.h";