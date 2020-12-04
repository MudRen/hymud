#include <ansi.h> 
#include <armor.h>

inherit WAIST;

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
	      set_name("[36mÀ¶ºçÖ®Ñü´ø[2;37;0m", ({ "lanhong waist", "waist" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "Ìõ");
		set("long", @LONG
[36mÀ¶ºçÖ®Ñü´ø[2;37;0mÕâÊÇÒ»ÌõÓÉÎŞ±È¼áÓ²µÄ[1;37mÈíÒø[2;37;0m¼ÓÉÏ[1;33mÄ¾ÃŞ»¨[2;37;0mÖÆ³É£¬ÖØÒ»½ïËÄÁ½ÎåÇ®µÄ[36mÀ¶ºçÖ®Ñü´ø[2;37;0m¡£
×ÛºÏÆÀ¼Û[37m¾øÊÀÎŞË«[2;37;0m ¿´ÆğÀ´ÎŞ±È¼á¹Ì£¬¾ßÓĞ[36m²»Ğ¡[2;37;0mµÄ·À»¤Á¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[37mÌì[2;37;0m:[1;35m¾øÊÀ[2;37;0m [1;36mÈË[2;37;0m:[1;36mÍêÃÀ[2;37;0m [1;31mÄ§[2;37;0m:[1;34m¾ÙÊÀ[2;37;0m 
ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
¼áÓ²:[1;31mÎŞË«[2;37;0m ÌìÓî:[34mÏ¸Ëé[2;37;0m ÌìÔ¨:[34mÏ¸Ëé[2;37;0m ÇÉÖÆ:[36m²»´í[2;37;0m 

ÒÔ¼°Ò»ÅÅ¹Å×­×Ö¡¾ [1;32mÊ·µÙ·ÒÖÜ[2;37;0m ¡¿¡£ºÍÒ»Ğ©¡¾ [1;32mÊÖ·¨[2;37;0m ¡¿µÄ¼¼ÇÉ¡£

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "xianoda");
		set("ownername", "Ê·µÙ·ÒÖÜ");
		set("value", 16000);
		set("armor_prop/intelligence",24);
		set("armor_prop/strength",48);
		set("armor_prop/karey",16);
		set("armor_prop/percao",48);
		set("armor_prop/dexerity",20);
		set("armor_prop/constitution",48);
    set("armor_prop/dodge", 32);
    set("armor_prop/parry", 48);
    set("armor_prop/attack", 24);


    set("armor_prop/armor", 420);
    set("armor_prop/defense", 40);
    
    set("armor_prop/neili", 48);
    set("armor_prop/qi", 40);
    set("armor_prop/jing", 40);
    set("armor_prop/jingli", 48);
    set("armor_prop/damage", 235);

    set("wtypeA",0);
    set("wtypeB",0);
    set("wtypeC",0);
    set("wtypeD",0);
    set("wtypeE",4);
    set("wtypeF",5);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",11);
    set("wtypeJ",0);
    set("wtypeK",7);
    set("wtypeL",8);
    
    
                set("skill", ([
                        "name": "hand",
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