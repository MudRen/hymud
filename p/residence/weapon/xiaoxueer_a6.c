#include <ansi.h> 
#include <armor.h>

inherit WRISTS;

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
"anqi_poison",
"nx_poison",
"chilian_poison",
"yufeng_poison",
"insect_poison",
"xscold_poison",
});

string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});  
void create()
{
	      set_name("[36m����֮����[2;37;0m", ({ "shenwang wrists", "wrists" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "˫");
		set("long", @LONG
[36m����֮����[2;37;0m����һ˫��ʮ�ּ�Ӳ��[1;33m����[2;37;0m����[32m���˿[2;37;0m�Ƴɣ������������Ǯ��[36m����֮����[2;37;0m��
�ۺ�����[37m������˫[2;37;0m ������ʮ�ּ�̣�����[36m��С[2;37;0m�ķ�������
������˼����ŷ��ţ�
[1;33m��[2;37;0m:[35m��׼[2;37;0m [36mľ[2;37;0m:[1;32mħ��[2;37;0m [32mˮ[2;37;0m:[1;31m��˫[2;37;0m [31m��[2;37;0m:[1;34m����[2;37;0m 
���滹����һЩ���֣�
��Ӳ:[1;31m��˫[2;37;0m ����:[34mϸ��[2;37;0m ����:[33m�ܸ�[2;37;0m 
��ʯ:[32m�ֲ�[2;37;0m ��ʯ:[34mϸ��[2;37;0m ����:[36m����[2;37;0m 

�Լ�һ�Ź�׭�֡� [1;32mСѩ��[2;37;0m ������һЩ�� [1;32mȭ��[2;37;0m ���ļ��ɡ�

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "xiaoxueer");
		set("ownername", "Сѩ��");
		set("value", 16000);
		set("armor_prop/intelligence",48);
		set("armor_prop/strength",23);
		set("armor_prop/karey",48);
		set("armor_prop/percao",48);
		set("armor_prop/dexerity",0);
		set("armor_prop/constitution",48);
    set("armor_prop/dodge", 48);
    set("armor_prop/parry", 26);
    set("armor_prop/attack", 17);


    set("armor_prop/armor", 267);
    set("armor_prop/defense", 48);
    
    set("armor_prop/neili", 0);
    set("armor_prop/qi", 48);
    set("armor_prop/jing", 48);
    set("armor_prop/jingli", 40);
    set("armor_prop/damage", 0);

    set("wtypeA",5);
    set("wtypeB",9);
    set("wtypeC",12);
    set("wtypeD",8);
    set("wtypeE",0);
    set("wtypeF",4);
    set("wtypeG",5);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",2);
    
    
                set("skill", ([
                        "name": "cuff",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 320,              
                ]) );		


		set("material", "default");
    set("sharpness", 12);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";