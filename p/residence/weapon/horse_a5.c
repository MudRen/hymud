#include <ansi.h> 
#include <armor.h>

inherit NECK;

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
	      set_name("[1;33mÌ«¼«Ö®ÏîÁ´[2;37;0m", ({ "taiji neck", "neck" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "´®");
		set("long", @LONG
[1;33mÌ«¼«Õß£¬ÎŞ¼«¶øÉú£¬ÒõÑôÖ®Ä¸Ò²¡£¶¯Ö®Ôò·Ö£¬¾²Ö®ÔòºÏ¡£ÎŞ¹ı²»¼°£¬ËæÇú¾ÍÉì¡£
ÈË¸ÕÎÒÈáÎ½Ö®×ß£¬ÎÒË³ÈË±³Î½Ö®Õ³¡£¶¯¼±Ôò¼±Ó¦£¬¶¯»ºÔò»ºËæ¡£Ëä±ä»¯Íò¶Ë£¬¶ø
ÀíÎªÒ»¹á£¡
[2;37;0mÕâÊÇÒ»´®ÓÉÏàµ±¼áÓ²µÄ[37mĞşÌú[2;37;0m¼ÓÉÏ[1;37m±ù²ÏË¿[2;37;0mÖÆ³É£¬ÖØ¶ş½ïÁùÁ½ÁùÇ®µÄ[1;33mÌ«¼«Ö®ÏîÁ´[2;37;0m¡£
×ÛºÏÆÀ¼Û[1;36mÎŞË«ÎŞ¶Ô[2;37;0m ¿´ÆğÀ´Ïàµ±¼á¹Ì£¬¾ßÓĞ[34m²»´í[2;37;0mµÄ·À»¤Á¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[40mµØ[2;37;0m:[1;36mÍêÃÀ[2;37;0m [1;33m½ğ[2;37;0m:[1;33mÌìÊ¥[2;37;0m [36mÄ¾[2;37;0m:[1;33mÌìÊ¥[2;37;0m [32mË®[2;37;0m:[1;31mÎŞË«[2;37;0m 
ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
¼áÓ²:[1;33mÃğÊÀ[2;37;0m ÇÉÖÆ:[33mºÜ¸ß[2;37;0m 
°×Ê¯:[31m¾«ÖÂ[2;37;0m ×ÏÊ¯:[32m´Ö²Ú[2;37;0m ³¤Éú:[1;36mÍêÃÀ[2;37;0m ²»ÀÏ:[33mºÜ¸ß[2;37;0m 
ÒÔ¼°Ò»ÅÅ¹Å×­×Ö¡¾ [1;32mĞ¡Âí[2;37;0m ¡¿¡£ºÍÒ»Ğ©¡¾ [1;32m×¦·¨[2;37;0m ¡¿µÄ¼¼ÇÉ¡£

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "horse");
		set("ownername", "Ğ¡Âí");
		set("value", 25000);
		set("armor_prop/intelligence",0);
		set("armor_prop/strength",32);
		set("armor_prop/karey",0);
		set("armor_prop/percao",0);
		set("armor_prop/dexerity",40);
		set("armor_prop/constitution",40);
    set("armor_prop/dodge", 66);
    set("armor_prop/parry", 31);
    set("armor_prop/attack", 0);


    set("armor_prop/armor", 373);
    set("armor_prop/defense", 40);
    
    set("armor_prop/neili", 48);
    set("armor_prop/qi", 70);
    set("armor_prop/jing", 46);
    set("armor_prop/jingli", 46);
    set("armor_prop/damage", 287);

    set("wtypeA",10);
    set("wtypeB",10);
    set("wtypeC",12);
    set("wtypeD",0);
    set("wtypeE",7);
    set("wtypeF",0);
    set("wtypeG",5);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",7);
    set("wtypeK",0);
    set("wtypeL",3);
    
    
                set("skill", ([
                        "name": "claw",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 300,              
                ]) );		


		set("material", "default");
    set("sharpness", 16);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";