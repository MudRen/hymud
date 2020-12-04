#include <ansi.h> 
#include <armor.h>

inherit CLOTH;

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
	      set_name("[1;31mÉñÍ¨Õ½ÒÂ[2;37;0m", ({ "zhendian cloth", "cloth" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¼ş");
		set("long", @LONG
[37mÕğµçÖ®·ş×°[2;37;0mÕâÊÇÒ»¼şÓÉÎŞ±È¼áÓ²µÄ[31mÍòÄêÉñÌú[2;37;0m¼ÓÉÏ[32mÓñ²ÏË¿[2;37;0mÖÆ³É£¬ÖØÈı½ï¶şÁ½°ËÇ®µÄ[37mÕğµçÖ®·ş×°[2;37;0m¡£
×ÛºÏÆÀ¼Û[37m¾øÊÀÎŞË«[2;37;0m ¿´ÆğÀ´ÎŞ±È¼á¹Ì£¬¾ßÓĞ[35m¼«Æä¿ÉÅÂ[2;37;0mµÄ·À»¤Á¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[40mµØ[2;37;0m:[1;32mÄ§Íõ[2;37;0m [1;31mÄ§[2;37;0m:[1;31mÎŞË«[2;37;0m [33mÍÁ[2;37;0m:[1;33mÌìÊ¥[2;37;0m [1;35m·ç[2;37;0m:[1;36mÍêÃÀ[2;37;0m 

ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
¼áÓ²:[1;31m¿ªÔª[2;37;0m ¸£Ô´:[36m²»´í[2;37;0m 
ÌìÔ¨:[36m²»´í[2;37;0m ÇÉÖÆ:[32m´Ö²Ú[2;37;0m 
ÌåÁé:[34mÏ¸Ëé[2;37;0m °×Ê¯:[34mÏ¸Ëé[2;37;0m ×ÏÊ¯:[34mÏ¸Ëé[2;37;0m ÍşÁ¦:[33mºÜ¸ß[2;37;0m 
ÒÔ¼°Ò»ÅÅ¹Å×­×Ö¡¾ [1;32mÅ·Ñô²»·â[2;37;0m ¡¿¡£ºÍÒ»Ğ©¡¾ [1;32mÕÆ·¨[2;37;0m ¡¿µÄ¼¼ÇÉ¡£

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "green");
		set("ownername", "Å·Ñô²»·â");
		set("value", 16000);
		set("armor_prop/intelligence",0);
		set("armor_prop/strength",0);
		set("armor_prop/karey",18);
		set("armor_prop/percao",0);
		set("armor_prop/dexerity",18);
		set("armor_prop/constitution",0);
    set("armor_prop/dodge", 28);
    set("armor_prop/parry", 26);
    set("armor_prop/attack", 0);


    set("armor_prop/armor", 370);
    set("armor_prop/defense", 48);
    
    set("armor_prop/neili", 0);
    set("armor_prop/qi", 0);
    set("armor_prop/jing", 0);
    set("armor_prop/jingli", 0);
    set("armor_prop/damage", 65);

    set("wtypeA",0);
    set("wtypeB",0);
    set("wtypeC",0);
    set("wtypeD",6);
    set("wtypeE",10);
    set("wtypeF",7);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",9);
    set("wtypeK",0);
    set("wtypeL",12);
    
    
                set("skill", ([
                        "name": "strike",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 320,              
                ]) );		


		set("material", "default");
    set("sharpness", 13);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";